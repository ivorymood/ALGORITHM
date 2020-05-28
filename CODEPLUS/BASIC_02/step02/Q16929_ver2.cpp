//https://www.acmicpc.net/problem/16929
#include <iostream>
#include <vector>

using namespace std;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };
int N, M;

/*
	�ּ� 4���� ���� �� ����Ŭ�� ��������⸸ �ϸ� �ȴ�.
	
	2���� ���� ���� �ٸ� ����� ���� �湮�� �� �ְ� ���� ��
	���� �湮�ߴ� ��带 �ٽ� �湮�ϰ� �ȴٸ� 
	����Ŭ�� ������ ����̴�. 
*/
bool dfs(vector<string>& map, vector<vector<bool>>& check, pair<int, int> now, pair<int, int> before)
{
	// ���� �湮�� ��ġ�� �� true��ȯ �� ����
	if (check[now.first][now.second])
	{
		return true;
	}

	// ���� ��ġ �湮 üũ
	check[now.first][now.second] = true;

	// 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		int new_x = now.first + dir_x[i];
		int new_y = now.second + dir_y[i];

		// �Ұ����� ��ġ�� ��
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
		{
			continue;
		}

		// ���� ���� ��
		if (map[now.first][now.second] == map[new_x][new_y])
		{
			// �� ������ ���� ������ �ٸ� ��
			if (!(new_x == before.first && new_y == before.second))
			{
				// �ѹ��̶� ����Ŭ�� �����ϸ� true��ȯ �� ����
				if (dfs(map, check, { new_x, new_y }, now))
				{
					return true;
				}
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

	// �湮���θ� üũ�� bool ����
	vector<vector<bool>> check(N, vector<bool>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// ���� �湮���� �ʾҴٸ�
			if (!check[i][j])
			{
				// dfs�� ����Ŭ�� ����������� ���� �˻�
				if (dfs(map, check, { i, j }, { -1, -1 }))
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