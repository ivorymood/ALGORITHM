//https://www.acmicpc.net/problem/6087
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int x, y;
};

int W, H;
const int MAX = 100;
char map[MAX][MAX + 1];
int mirror[MAX][MAX];
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};

int bfs(pos start, pos end)
{
	// mirror배열을 -1로 초기화
	memset(mirror, -1, sizeof(mirror));

	// 큐에 시작위치 push
	queue<pos> q;
	q.push(start);

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// 끝점에 도착하면 : 끝점의 mirror값 반환
		if (p.x == end.x && p.y == end.y)
		{
			return mirror[p.x][p.y];
		}

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			/*
				한 방향으로 벽에 닿기 전 / map의 끝까지 mirror값을 매긴다.
				빛이 꺾이지 않는다면 mirror값은 직선방향으로 동일하기 때문.
			*/
			while (!(nx < 0 || nx >= H || ny < 0 || ny >= W))
			{
				if (map[nx][ny] == '*')
				{
					break;
				}

				/*
					mirror값이 아직 체크되지 않았다면
					현재의 거울 값 + 1 저장 후 큐에 push
				*/
				if (mirror[nx][ny] < 0)
				{	
					mirror[nx][ny] = mirror[p.x][p.y] + 1;
					q.push({nx, ny});
				}

				// 같은 방향 다음 위치로 이동
				nx += dr_x[i];
				ny += dr_y[i];
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
	cin >> W >> H;
	vector<pos> SnE;
	for (int i = 0; i < H; ++i)
	{
		cin >> map[i];
		
		for (int j = 0; j < W; ++j)
		{
			// 시작점, 끝점
			if (map[i][j] == 'C')
			{
				SnE.push_back({i, j});
			}
		}
	}

	// 시작 ~ 끝 점까지 총 몇개의 거울이 필요한지 출력
	cout << bfs(SnE[0], SnE[1]);

	return 0;
}