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
	int min_dist = 987654321;	// ���� �� �ִ� �������� �ּҰŸ�

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// min_dist���� ū ��δ� �ǹ̰� ����
		if (dist[p.x][p.y] > min_dist)
		{
			continue;
		}

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			// �̹� �Ÿ��� ���߰ų� ��������� �� Ŭ ��
			if (dist[nx][ny] >= 0 || map[nx][ny] > size)
			{
				continue;
			}

			// �Ÿ����� ���� �� �� ť�� push
			dist[nx][ny] = dist[p.x][p.y] + 1;
			q.push({ nx, ny });

			// ���� �� �ִ� ������̸�
			if (map[nx][ny] > 0 && map[nx][ny] < size)
			{
				// �Ÿ��� min_dist���� ũ�� X
				if (dist[nx][ny] > min_dist)
				{
					continue;
				}
				// �� ��, �� ������ ���� �� �ִ� ����� ��ġ ���ϱ�
				if ((nx < next.x || (nx == next.x && ny < next.y)))
				{
					next = { nx, ny };
					min_dist = dist[nx][ny];
				}

				fish = true;
			}
		}
	}

	// ���� �� �ִ� ����Ⱑ ���ٸ�
	if (!fish)
	{
		next = { -1, -1 };
	}
	return next;
}

int fish_time(pos start, int size, int ate, int time)
{
	// ���� �� �ִ� ���� ����� ��ġ�� bfs�� Ž��
	pos next = bfs_get_next_pos(start, size);
	if (next.x == -1)
	{
		return time;
	}

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

			// �Ʊ� ��� ��ġ ���� �� map[i][j]�� 0���� ��ü
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