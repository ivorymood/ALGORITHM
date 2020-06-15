//https://www.acmicpc.net/problem/3055
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

struct pos
{
	int x, y;
};

int R, C;
const int MAX = 50;
char map[MAX][MAX + 1];
int water_time[MAX][MAX + 1];
bool visit[MAX][MAX];
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };

int bfs(pos start, pos end)
{
	queue<tuple<pos, int>> q;
	q.push({ start, 0 });
	visit[start.x][start.y] = true;

	while (!q.empty())
	{
		pos p;
		int time;
		tie(p, time) = q.front();
		q.pop();

		// 끝점에 도착하면 시간 반환
		if (p.x == end.x && p.y == end.y)
		{
			return time;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}

			// 다음 칸이 돌이거나, 이미 방문한 적 있을 때
			if (map[nx][ny] == 'X' || visit[nx][ny])
			{
				continue;
			}

			// 다음 지점이 물이 없는 지역이거나(D), 물이 차는 시간 전에 도착할 때
			if (water_time[nx][ny] < 0 || water_time[nx][ny] > time + 1)
			{
				visit[nx][ny] = true;
				q.push({ {nx, ny}, time + 1 });
			}
		}
	}

	// 불가능한 경우
	return -1;
}

/*
	water_q큐의 물 지점으로부터 몇 초 후에 물이 차게 되는지
	water_time배열에 bfs로 기록
*/
void bfs_water_time(queue<tuple<pos, int>>& water_q)
{
	while (!water_q.empty())
	{
		pos p;
		int time;
		tie(p, time) = water_q.front();
		water_q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}

			// map[nx][ny]가 빈칸이고, water_time[nx][ny]에 아직 기록한 적 없을 때
			if (map[nx][ny] == '.' && water_time[nx][ny] < 0)
			{
				water_time[nx][ny] = time + 1;
				water_q.push({ { nx, ny }, time + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
		water_time배열 : t초 후에 물이 있게 되는지 저장
		-1 값으로 초기화 (= 물 없음)
	*/
	memset(water_time, -1, sizeof(water_time));
	
	// 입력
	cin >> R >> C;
	pos start, end;
	queue<tuple<pos, int>> water_q;
	for (int i = 0; i < R; ++i)
	{
		cin >> map[i];

		for (int j = 0; j < C; ++j)
		{
			// 고슴도치 : 시작점
			if (map[i][j] == 'S')
			{
				start = { i, j };
			}
			// 비버 : 끝점
			else if (map[i][j] == 'D')
			{
				end = { i, j };
			}
			// 물 : water_q 큐에 push, water_time[x][y]에 0 저장
			else if (map[i][j] == '*')
			{
				water_q.push({ {i, j}, 0 });
				water_time[i][j] = 0;
			}
		}
	}

	// water_time배열에 몇초 후에 물이 차게 되는지 bfs로 기록
	bfs_water_time(water_q);


	// 시작점 ~ 끝점 까지 물을 만나지 않고 가는 최단거리
	int time = bfs(start, end);


	// 불가능할 경우
	if (time < 0)
	{
		cout << "KAKTUS";
	}
	// 가능할 경우
	else
	{
		cout << time;
	}

	return 0;
}