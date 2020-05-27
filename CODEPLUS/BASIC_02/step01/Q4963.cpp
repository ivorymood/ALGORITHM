//https://www.acmicpc.net/problem/4963
#include <iostream>
#include <vector>

using namespace std;

int dir_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dir_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int w, h;

// ���� �켱 Ž��
void dfs(vector<vector<int>> &map, int x, int y)
{
	// �湮�� ��ġ�� 0 ����
	map[x][y] = 0;

	// �밢���� �����ؼ� 8���� ���� Ž��
	for (int i = 0; i < 8; ++i)
	{
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		// �̵� ��ġ�� map ���� �ȿ� �ְ�
		if (0 <= new_x && new_x < h && 0 <= new_y && new_y < w)
		{
			// ���� 1�� ��ġ��(���� �湮�ϱ� ��) dfs �Լ� ��� ȣ��
			if (map[new_x][new_y] > 0)
			{
				dfs(map, new_x, new_y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		// �Է�
		cin >> w >> h;
		if (w == 0)
		{
			break;
		}
		vector<vector<int>> map(h, vector<int>(w));
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> map[i][j];
			}
		}

		// map Ž��
		int island = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				// ���� 1�� apt[i][j](���� �湮�ϱ� ��)���� ���̿켱 Ž��
				if (map[i][j] > 0)
				{
					// �ϳ��� Ž�������� ���۵Ǹ� island + 1
					++island;
					dfs(map, i, j);
				}

			}
		}

		// ���
		cout << island << '\n';
	}

	return 0;
}