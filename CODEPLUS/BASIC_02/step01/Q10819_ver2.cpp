//https://www.acmicpc.net/problem/10819
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int get_dif_sum(int numbers[], int N)
{
	int t_dif = 0;
	for (int i = 1; i < N; ++i)
	{
		t_dif += abs(numbers[i] - numbers[i - 1]);
	}
	return t_dif;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 8;
	int nums[MAX];

	// �Է�
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	// �������� ����
	sort(nums, nums + N);

	// ���ڰ��� �ִ� ���̰� �հ� ���ϱ�
	int max_dif = 0;
	do {
	
		int t_dif = get_dif_sum(nums, N);
		if (max_dif < t_dif)
		{
			max_dif = t_dif;
		}
	
	} while (next_permutation(nums, nums + N));

	// ���
	cout << max_dif;

	return 0;
}