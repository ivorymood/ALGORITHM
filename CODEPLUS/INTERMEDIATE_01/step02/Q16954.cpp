//https://www.acmicpc.net/problem/16954
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int N = 8;
char map[N][N + 1];
bool visit[N][N][N];
int dr_x[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dr_y[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};

int bfs()
{
	// map[N - 1][0] 에서 0초로 시작
	queue<tuple<int, int, int>> q;
	q.push({ N - 1, 0, 0 });
	visit[N - 1][0][0] = true;

	while (!q.empty())
	{
		int x, y, time;
		tie(x, y, time) = q.front();
		q.pop();
		
		if (x == 0 && y == N - 1)
		{
			return 1;
		}
		
		// N초 후에는 map에 벽이 없게되므로 시간을 카운트 하는 것이 의미가 없다.
		int nt = min(time + 1, N);
		
		// 제자리 + 대각선 + 상하좌우 총 9방향 탐색
		for (int i = 0; i < 9; ++i)
		{
			int nx = x + dr_x[i];
			int ny = y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			/*
				1. t초 후의 map[x][y]는 map[x - t][y]와 같다.
				2. 다음위치가 현재 벽인지, 1초 후에 벽인지 체크 후 이동
				3. N초 후에는 2번 체크가 의미가 없다. map에 장애물이 없으므로
			*/
			if ((nx - time >= 0 && map[nx - time][ny] == '#')
				|| (nx - time - 1 >= 0 && map[nx - time - 1][ny] == '#'))
			{
				continue;
			}

			/*
				map[x][y]에 동일하게 t초 후에 방문했었다면
				다시 방문하는 것이 의미가 없다.
			*/
			if (!visit[nx][ny][nt])
			{
				visit[nx][ny][nt] = true;
				q.push({ nx, ny, nt });
			}
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// map[N - 1][0] -> map[0][N - 1] 도착할 수 있는지 여부 출력
	cout << bfs();

	return 0;
}