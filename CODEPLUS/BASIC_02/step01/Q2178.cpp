//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
int map[MAX][MAX];
bool check[MAX][MAX];
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };
int N, M;

struct info {
	int x;
	int y;
	int depth;
};

int bfs()
{
	// 큐 선언 후 시작점과 깊이값 push
	queue<info> q;
	q.push({ 0, 0, 1 });

	// 큐가 빌 때까지 반복문
	while (!q.empty())
	{
		info tmp = q.front();
		q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int depth = tmp.depth;

		// 큐가 map[N][M]에 도착하면 깊이값 반환 및 종료
		if (x == N - 1 && y == M - 1)
		{
			return depth;
		}

		// 4가지 방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			// 다음 지점이 map 범위 내에 있고
			if (0 <= new_x && new_x < N && 0 <= new_y && new_y < M)
			{
				// 다음 지점을 아직 방문하지 않았고 이동할 수 있는 칸일 때 
				if (!check[new_x][new_y] && map[new_x][new_y] > 0)
				{
					// 큐에 중복해서 push하지 않도록 check
					check[new_x][new_y] = true;
					// 다음 지점 위치와 현재 깊이보다 1 큰 값 push
					q.push({ new_x , new_y, depth + 1 });
				}
			}
		}
	}
	return 0;
}

int main()
{
	// 입력
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	// 너비우선 탐색으로 미로 순회 후 최소값 출력
	printf("%d\n", bfs());

	return 0;
}