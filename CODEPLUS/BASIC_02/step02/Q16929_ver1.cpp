//https://www.acmicpc.net/problem/16929
#include <iostream>
#include <vector>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
int N, M;

// ���� �켱 Ž��
bool dfs(vector<string> &map, vector<vector<int>> &check, int x, int y)
{
	// 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		// �Ұ����� ��ġ�� ��
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
		{
			continue;
		}

		// ���� ���� ��
		if (map[x][y] == map[new_x][new_y])
		{
			// ���� �湮���� ���� ��ġ�� ��, 
			// �̵�Ƚ���� ���� �̵�Ƚ�� + 1 ���� �� dfs ���ȣ��
			if (check[new_x][new_y] == 0)
			{
				check[new_x][new_y] = check[x][y] + 1;
				// �ѹ��̶� ����Ŭ�� �����ϸ� true��ȯ �� ����
				if (dfs(map, check, new_x, new_y))
				{
					return true;
				}
			}
			// ������ �湮�ߴ� ��ġ�� ��, ���� �̵�Ƚ���� ��� 3�̻� ���̳��� true��ȯ
			else if (check[new_x][new_y] - check[x][y] >= 3)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// �̵� Ƚ���� ������ int ����
	vector<vector<int>> check(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// ���� �湮���� ���� ��ġ���
			if (check[i][j] == 0)
			{
				// �湮Ƚ���� 1�� ���� 
				check[i][j] = 1;
				
				// dfs�� ����Ŭ�� ����������� ���� �˻�
				if (dfs(map, check, i, j)) 
				{
					cout << "Yes";
					return 0;
				}
			}
		}
	}

	cout << "No";

	return 0;
}