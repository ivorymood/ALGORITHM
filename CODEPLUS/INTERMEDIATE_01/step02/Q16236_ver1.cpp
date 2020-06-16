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

int bfs(pos start, int size)
{
	memset(dist, -1, sizeof(dist));

	queue<pos> q;
	q.push(start);
	dist[start.x][start.y] = 0;

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// 상어가 먹을 수 있는 물고기일 때 거리값 반환
		if (map[p.x][p.y] > 0 && map[p.x][p.y] < size)
		{
			return dist[p.x][p.y];
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			// 이미 거리값을 매겼거나, 물고기가 상어보다 크면
			if (dist[nx][ny] >= 0 || map[nx][ny] > size)
			{
				continue;
			}

			// dist배열에 거리값을 저장하고 큐에 push
			dist[nx][ny] = dist[p.x][p.y] + 1;
			q.push({ nx, ny });
		}
	}
	return -1;
}

pos get_next_pos(int size, int closest)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (dist[i][j] == closest && map[i][j] > 0 && map[i][j] < size)
			{
				return { i, j };
			}
		}
	}
	return { -1, -1 };
}

int fish_time(pos start, int size, int ate, int time)
{
	// 먹을수 있는 가장 가까운 물고기와의 거리
	int closest_ok_fish = bfs(start, size);
	if (closest_ok_fish < 0)
	{
		return time;
	}

	/*
		위에서 구한 closest_ok_fish와 동일한 거리에 있고
		먹을 수 있는 맨위, 맨 왼쪽의 물고기 위치
	*/
	pos next = get_next_pos(size, closest_ok_fish);
	map[next.x][next.y] = 0;

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
	return fish_time(next, size, ate, time + dist[next.x][next.y]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;
	pos start;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];

			// 아기상어 일때
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