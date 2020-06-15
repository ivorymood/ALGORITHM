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

		// ������ �����ϸ� �ð� ��ȯ
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

			// ���� ĭ�� ���̰ų�, �̹� �湮�� �� ���� ��
			if (map[nx][ny] == 'X' || visit[nx][ny])
			{
				continue;
			}

			// ���� ������ ���� ���� �����̰ų�(D), ���� ���� �ð� ���� ������ ��
			if (water_time[nx][ny] < 0 || water_time[nx][ny] > time + 1)
			{
				visit[nx][ny] = true;
				q.push({ {nx, ny}, time + 1 });
			}
		}
	}

	// �Ұ����� ���
	return -1;
}

/*
	water_qť�� �� �������κ��� �� �� �Ŀ� ���� ���� �Ǵ���
	water_time�迭�� bfs�� ���
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

			// map[nx][ny]�� ��ĭ�̰�, water_time[nx][ny]�� ���� ����� �� ���� ��
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
		water_time�迭 : t�� �Ŀ� ���� �ְ� �Ǵ��� ����
		-1 ������ �ʱ�ȭ (= �� ����)
	*/
	memset(water_time, -1, sizeof(water_time));
	
	// �Է�
	cin >> R >> C;
	pos start, end;
	queue<tuple<pos, int>> water_q;
	for (int i = 0; i < R; ++i)
	{
		cin >> map[i];

		for (int j = 0; j < C; ++j)
		{
			// ����ġ : ������
			if (map[i][j] == 'S')
			{
				start = { i, j };
			}
			// ��� : ����
			else if (map[i][j] == 'D')
			{
				end = { i, j };
			}
			// �� : water_q ť�� push, water_time[x][y]�� 0 ����
			else if (map[i][j] == '*')
			{
				water_q.push({ {i, j}, 0 });
				water_time[i][j] = 0;
			}
		}
	}

	// water_time�迭�� ���� �Ŀ� ���� ���� �Ǵ��� bfs�� ���
	bfs_water_time(water_q);


	// ������ ~ ���� ���� ���� ������ �ʰ� ���� �ִܰŸ�
	int time = bfs(start, end);


	// �Ұ����� ���
	if (time < 0)
	{
		cout << "KAKTUS";
	}
	// ������ ���
	else
	{
		cout << time;
	}

	return 0;
}