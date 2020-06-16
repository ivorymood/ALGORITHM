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
	// mirror�迭�� -1�� �ʱ�ȭ
	memset(mirror, -1, sizeof(mirror));

	// ť�� ������ġ push
	queue<pos> q;
	q.push(start);

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// ������ �����ϸ� : ������ mirror�� ��ȯ
		if (p.x == end.x && p.y == end.y)
		{
			return mirror[p.x][p.y];
		}

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			/*
				�� �������� ���� ��� �� / map�� ������ mirror���� �ű��.
				���� ������ �ʴ´ٸ� mirror���� ������������ �����ϱ� ����.
			*/
			while (!(nx < 0 || nx >= H || ny < 0 || ny >= W))
			{
				if (map[nx][ny] == '*')
				{
					break;
				}

				/*
					mirror���� ���� üũ���� �ʾҴٸ�
					������ �ſ� �� + 1 ���� �� ť�� push
				*/
				if (mirror[nx][ny] < 0)
				{	
					mirror[nx][ny] = mirror[p.x][p.y] + 1;
					q.push({nx, ny});
				}

				// ���� ���� ���� ��ġ�� �̵�
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

	// �Է�
	cin >> W >> H;
	vector<pos> SnE;
	for (int i = 0; i < H; ++i)
	{
		cin >> map[i];
		
		for (int j = 0; j < W; ++j)
		{
			// ������, ����
			if (map[i][j] == 'C')
			{
				SnE.push_back({i, j});
			}
		}
	}

	// ���� ~ �� ������ �� ��� �ſ��� �ʿ����� ���
	cout << bfs(SnE[0], SnE[1]);

	return 0;
}