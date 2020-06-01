//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// ����� ������ -10�� ~ 10��
int max_num = numeric_limits<int>::min();
int min_num = numeric_limits<int>::max();

// �־��� ������ �ε����� ���
int calc(int op, int num1, int num2)
{
	if (op == 0)
	{
		return num1 + num2;
	}
	else if (op == 1)
	{
		return num1 - num2;
	}
	else if (op == 2)
	{
		return num1 * num2;
	}
	else if (op == 3)
	{
		return num1 / num2;
	}
	return 0;
}

void dfs(vector<int> &nums, vector<int> &strg, int res, int depth)
{
	if (depth == nums.size())
	{
		max_num = max(max_num, res);
		min_num = min(min_num, res);
		return;
	}

	for (int j = 0; j < 4; ++j)
	{
		// ���� ������ Ƚ���� ����������
		if (strg[j] > 0)
		{
			--strg[j];
			// ���� ����� ������ڸ� ������ ������ dfs�Լ� ���ȣ��
			dfs(nums, strg, calc(j, res, nums[depth]), depth + 1);
			++strg[j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	vector<int> strg(4);
	for (int i = 0; i < 4; ++i)
	{
		cin >> strg[i];
	}

	// ��Ʈ��ŷ���� ������ ��� ���� ���ؼ� �ִ밪/�ּҰ� �����ϱ�
	dfs(nums, strg, nums[0], 1);

	// ���
	cout << max_num << '\n';
	cout << min_num << '\n';

	return 0;
}