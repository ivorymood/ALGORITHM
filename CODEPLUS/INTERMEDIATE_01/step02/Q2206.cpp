//https://www.acmicpc.net/problem/2206
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int x, y;
};

struct info {
	pos p;
	int left; // left 만큼 벽을 부술 수 있다
	int dist; // 이동횟수
};

int N, M;
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};
const int MAX = 1000;
int visit[MAX][MAX];

int bfs(vector<string>& map)
{
	// visit : 여분의 부술 벽 개수를 저장할 배열
	// -1값으로 초기화
	memset(visit, -1, sizeof(visit));

	// map[0][0]부터, 부술수 있는 벽 1개, 이동횟수 1로 시작
	queue<info> q;
	q.push({0, 0, 1, 1});
	
	// map[0][0]에 도착했을 때 부술 수 있는 벽 개수 1개
	visit[0][0] = 1;

	while (!q.empty())
	{
		pos p = q.front().p;
		int left = q.front().left;
		int dist = q.front().dist;
		q.pop();

		// map[N - 1][M - 1]에 도착하면 이동횟수 반환
		if (p.x == N - 1 && p.y == M - 1)
		{
			return dist;
		}

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			// 범위를 벗어나면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			/*
				다음위치가 빈칸이고, 
				여분의 벽 개수가 더 적을 때 해당 지점을 방문했었다면
			*/
			if (map[nx][ny] == '0' && visit[nx][ny] < left)
			{
				// visit[nx][ny]에 현재 여분 벽 개수 저장
				visit[nx][ny] = left;
				
				// 이동횟수 + 1 하고 현재 정보를 큐에 push
				q.push({ nx, ny, left, dist + 1 });
			}
			/*
				부술 수 있는 벽 개수가 남아있고, 다음위치가 벽이고, 
				여분의 벽 개수가 더 적을 때 해당 지점을 방문했었다면
			*/
			else if (left > 0 && map[nx][ny] == '1' && visit[nx][ny] < left - 1)
			{
				// visit[nx][ny]에 부수고 난 후 여분 벽 개수 저장
				visit[nx][ny] = left - 1;

				// 이동횟수 + 1 하고 현재 정보를 큐에 push
				q.push({ nx, ny, left - 1, dist + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// map[0][0] ~ map[N - 1][M - 1] 최단 거리 출력
	cout << bfs(map);

	return 0;
}