//https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct pos {
	int x, y;
};

int N;
const int MAX = 20;
int map[MAX][MAX];
int dist[MAX][MAX];
int dr_x[] = { -1, 0, 1, 0 };
int dr_y[] = { 0, -1, 0, 1 };

pos bfs_get_next_pos(pos start, int size)
{
	memset(dist, -1, sizeof(dist));

	queue<pos> q;
	q.push(start);
	dist[start.x][start.y] = 0;

	pos next = { N, N };
	bool fish = false;
	int min_dist = 987654321;	// 먹을 수 있는 물고기와의 최소거리

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// min_dist보다 큰 경로는 의미가 없다
		if (dist[p.x][p.y] > min_dist)
		{
			continue;
		}

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			// 이미 거리를 구했거나 물고기사이즈가 더 클 때
			if (dist[nx][ny] >= 0 || map[nx][ny] > size)
			{
				continue;
			}

			// 거리값을 저장 한 후 큐에 push
			dist[nx][ny] = dist[p.x][p.y] + 1;
			q.push({ nx, ny });

			// 먹을 수 있는 물고기이면
			if (map[nx][ny] > 0 && map[nx][ny] < size)
			{
				// 거리가 min_dist보다 크면 X
				if (dist[nx][ny] > min_dist)
				{
					continue;
				}
				// 맨 위, 맨 왼쪽의 먹을 수 있는 물고기 위치 구하기
				if ((nx < next.x || (nx == next.x && ny < next.y)))
				{
					next = { nx, ny };
					min_dist = dist[nx][ny];
				}

				fish = true;
			}
		}
	}

	// 먹을 수 있는 물고기가 없다면
	if (!fish)
	{
		next = { -1, -1 };
	}
	return next;
}

int fish_time(pos start, int size, int ate, int time)
{
	// 먹을 수 있는 다음 물고기 위치를 bfs로 탐색
	pos next = bfs_get_next_pos(start, size);
	if (next.x == -1)
	{
		return time;
	}

	// 현재 size만큼 먹으면 상어는 크기가 1 커진다
	if (++ate == size)
	{
		++size;
		ate = 0;
	}

	/*
		상어의 위치는 위에서 구한 물고기 위치로 대체.
		시간은 물고기 위치까지의 거리를 더한 값으로 fish_time 재귀호출
	*/
	map[next.x][next.y] = 0;
	return fish_time(next, size, ate, time + dist[next.x][next.y]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	pos start;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];

			// 아기 상어 위치 저장 후 map[i][j]은 0으로 대체
			if (map[i][j] == 9)
			{
				start = { i, j };
				map[i][j] = 0;
			}
		}
	}

	// 먹을 수 있는 물고기를 모두 먹기까지 걸리는 시간 출력
	cout << fish_time(start, 2, 0, 0);

	return 0;
}