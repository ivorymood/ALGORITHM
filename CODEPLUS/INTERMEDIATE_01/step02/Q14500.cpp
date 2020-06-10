//https://www.acmicpc.net/problem/14500
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr_x[4] = {0, 1, 0, -1};
int dr_y[4] = {1, 0, -1, 0};
int N, M, max_sum;

// �Ǹ� ������ ������ ���� üũ
void dfs(vector<vector<int>> &nums, vector<vector<bool>> &visit, int x, int y, int sum, int depth)
{
	// 4��° ĭ �̵��� ���� ���
	if (depth == 4)
	{
		max_sum = max(sum, max_sum);
		return;
	}
	// �̵��� �Ұ����� ���
	if (x < 0 || x >= N || y < 0 || y >= M)
	{
		return;
	}
	// �̹� ������ ĭ�� ���
	if (visit[x][y])
	{
		return;
	}

	// �̵������� 4���� Ž�� �� dfs����Լ� ȣ��
	visit[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		dfs(nums, visit, x + dr_x[i], y + dr_y[i], sum + nums[x][y], depth + 1);
	}
	visit[x][y] = false;
}

// �Ǹ�� ���� üũ
void check_t_shape(vector<vector<int>>& nums, int x, int y)
{
	if (x + 2 < N)
	{
		int sum = nums[x][y] + nums[x + 1][y] + nums[x + 2][y];
		if (y - 1 >= 0)
		{
			max_sum = max(sum + nums[x + 1][y - 1], max_sum);
		}
		if (y + 1 < M)
		{
			max_sum = max(sum + nums[x + 1][y + 1], max_sum);
		}
	}

	if (y + 2 < M)
	{
		int sum = nums[x][y] + nums[x][y + 1] + nums[x][y + 2];
		if (x - 1 >= 0)
		{
			max_sum = max(sum + nums[x - 1][y + 1], max_sum);
		}
		if (x + 1 < N)
		{
			max_sum = max(sum + nums[x + 1][y + 1], max_sum);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> M;
	vector<vector<int>> nums(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> nums[i][j];
		}
	}

	// �Է¹��� �迭 Ž���ϸ� ��Ʈ�ι̳� �հ� ���ϱ�
	vector<vector<bool>> visit(N, vector<bool>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			/*
				�Ǹ� ������ ������ ����
				: �ش� ��ġ���� �̵������� �������� 3ĭ�̵��ϸ� �հ� ���ϰ� max�� üũ
			*/
			dfs(nums, visit, i, j, 0, 0);

			// �Ǹ�� ���� üũ
			check_t_shape(nums, i, j);
		}
	}

	// ���
	cout << max_sum;

	return 0;
}