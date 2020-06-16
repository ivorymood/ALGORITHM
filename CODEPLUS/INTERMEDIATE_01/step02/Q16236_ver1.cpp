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

		// �� ���� �� �ִ� ������� �� �Ÿ��� ��ȯ
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

			// �̹� �Ÿ����� �Ű�ų�, ����Ⱑ ���� ũ��
			if (dist[nx][ny] >= 0 || map[nx][ny] > size)
			{
				continue;
			}

			// dist�迭�� �Ÿ����� �����ϰ� ť�� push
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
	// ������ �ִ� ���� ����� �������� �Ÿ�
	int closest_ok_fish = bfs(start, size);
	if (closest_ok_fish < 0)
	{
		return time;
	}

	/*
		������ ���� closest_ok_fish�� ������ �Ÿ��� �ְ�
		���� �� �ִ� ����, �� ������ ����� ��ġ
	*/
	pos next = get_next_pos(size, closest_ok_fish);
	map[next.x][next.y] = 0;

	// ���� size��ŭ ������ ���� ũ�Ⱑ 1 Ŀ����
	if (++ate == size)
	{
		++size;
		ate = 0;
	}

	/*
		����� ��ġ�� ������ ���� ����� ��ġ�� ��ü.
		�ð��� ����� ��ġ������ �Ÿ��� ���� ������ fish_time ���ȣ��
	*/
	return fish_time(next, size, ate, time + dist[next.x][next.y]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N;
	pos start;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];

			// �Ʊ��� �϶�
			if (map[i][j] == 9)
			{
				start = { i, j };
				map[i][j] = 0;
			}
		}
	}

	// ���� �� �ִ� ����⸦ ��� �Ա���� �ɸ��� �ð� ���
	cout << fish_time(start, 2, 0, 0);

	return 0;
}