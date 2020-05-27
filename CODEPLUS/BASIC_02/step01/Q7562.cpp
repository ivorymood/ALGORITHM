//https://www.acmicpc.net/problem/7562
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �ʺ� �켱 Ž������ ��ǥ���������� �ּҰŸ� ���ϱ�
int bfs(int size, pair<int, int> strt, pair<int, int> fin)
{
	// ����Ʈ�� �̵������� 8����
	const int dir_x[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	const int dir_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	vector<vector<int>> map(size, vector<int>(size));
	queue<pair<int, int>> q;

	// ���������� ť�� push
	q.push(strt);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// ��ǥ������ �����ϸ� map[x][y] = �̵�Ƚ�� ��ȯ
		if (x == fin.first && y == fin.second)
		{
			return map[x][y];
		}

		// 8���� Ž��
		for (int i = 0; i < 8; ++i)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			// �̵��� �� ���� ��ġ�� ��
			if (new_x < 0 || new_x >= size || new_y < 0 || new_y >= size)
			{
				continue;
			}

			// ���� �湮���� ���� ��ġ�� �� --> map�� �̵�Ƚ�� ����, ť�� push
			if (map[new_x][new_y] == 0)
			{
				map[new_x][new_y] = map[x][y] + 1;
				q.push({new_x, new_y});
			}
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		// �Է�
		int size;
		pair<int, int> strt, fin;
		cin >> size;
		cin >> strt.first >> strt.second;
		cin >> fin.first >> fin.second;

		// �ʺ� �켱 Ž������ ��ǥ���������� �ּҰŸ� ���� �� ���
		cout << bfs(size, strt, fin) << '\n';
	}

	return 0;
}