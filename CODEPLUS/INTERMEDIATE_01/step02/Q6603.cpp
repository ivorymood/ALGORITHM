//https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &nums, vector<bool> &check, int cnt, int depth)
{
	// ������ ������ 6���� �Ǿ��� �� ���
	if (cnt == 6)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			if (check[i])
			{
				cout << nums[i] << ' ';
			}
		}
		cout << '\n';

		return;
	}
	// 6���� �����ϱ� ���� ���ڿ��� ������ ��
	else if (depth == nums.size())
	{
		return;
	}

	// depth ��° ���ڸ� �����ϴ� ���
	check[depth] = true;
	dfs(nums, check, cnt + 1, depth + 1);
	check[depth] = false;

	// depth ��° ���ڸ� �������� �ʴ� ���
	dfs(nums, check, cnt, depth + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		// �Է�
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		vector<int> nums(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> nums[i];
		}

		// ���� ���θ� üũ�� bool ����
		vector<bool> check(N);
		// ��Ʈ��ŷ���� 6�� ���� ����
		dfs(nums, check, 0, 0);
		cout << '\n';
	}

	return 0;
}