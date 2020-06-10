//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// ����� ������ -10�� ~ 10��
int max_num = numeric_limits<int>::min();
int min_num = numeric_limits<int>::max();

// �־��� ������ �迭�� ���
int calc(vector<int> &nums, vector<int> &strg)
{
	int sum = nums[0];
	for (int i = 0; i < strg.size(); ++i)
	{
		int op = strg[i];
		if (op == 0)
		{
			sum += nums[i + 1];
		}
		else if (op == 1)
		{
			sum -= nums[i + 1];
		}
		else if (op == 2)
		{
			sum *= nums[i + 1];
		}
		else if (op == 3)
		{
			sum /= nums[i + 1];
		}
	}
	return sum;
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

	vector<int> strg(N - 1);
	int idx = 0;
	for (int i = 0; i < 4; ++i)
	{
		int cnt;
		cin >> cnt;
		while (cnt--)
		{
			strg[idx++] = i;
		}
	}

	// ������ ������ ��� ������� ���ؼ� �ִ밪/�ּҰ� �����ϱ�
	do {

		int res = calc(nums, strg);

		max_num = max(res, max_num);
		min_num = min(res, min_num);

	} while (next_permutation(strg.begin(), strg.end()));

	// ���
	cout << max_num << '\n';
	cout << min_num << '\n';

	return 0;
}