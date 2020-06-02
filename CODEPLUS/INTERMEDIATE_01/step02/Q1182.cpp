//https://www.acmicpc.net/problem/1182
#include <iostream>
#include <vector>

using namespace std;

int cnt;

void dfs(vector<int> &nums, vector<bool> &check, int S, int idx)
{
	// ���ڿ��� ���� �����ϸ�
	if (idx == nums.size())
	{
		// true üũ�� ���ڵ� (= �κ�����) �հ� ���ϱ�
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (check[i])
			{
				sum += nums[i];
			}
		}

		// �հ谡 S�̸� ī����
		if (sum == S)
		{
			++cnt;
		}

		return;
	}

	// idx��° ���ڸ� ������ ��
	check[idx] = true;
	dfs(nums, check, S, idx + 1);
	check[idx] = false;

	// idx��° ���ڸ� �������� ���� ��
	dfs(nums, check, S, idx + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, S;
	cin >> N >> S;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	// ��Ʈ��ŷ���� �κ������� �հ� ���ϱ�
	vector<bool> check(N);
	dfs(nums, check, S, 0);

	// S�� 0�� ���, �ƹ��͵� �������� �ʴ� ��쵵 ī���� �ǹǷ� -1
	if (S == 0) 
	{
		--cnt;
	}

	// ���
	cout << cnt;

	return 0;
}