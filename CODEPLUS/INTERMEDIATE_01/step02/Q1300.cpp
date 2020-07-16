//https://www.acmicpc.net/problem/1300
#include <iostream>
#include <algorithm>

using namespace std;

// �� ���� ���� int������ ���� �� �ֱ� ������ long long ������ ����
long long N, K;

// num���� �� ���� ���� ���� ���ϱ�
long long count_smaller(long long num)
{
	// �� ���� [1, N] ������ ���� ���� �ݺ���
	long long cnt = 0;
	for (long long i = 1, j = N; i <= N && j > 0; ++i)
	{
		// �� ���� ���� num���� ũ�� --j
		while (i * j >= num)
		{
			--j;
		}

		if (j > 0)
		{
			cnt += j;
		}
	}

	return cnt;
}

// �̺�Ž������ K��° �� ���ϱ�
long long binary_search(long long left, long long right)
{
	long long ans = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		// mid���� �� ���� ���� ������ K���� ������ 
		if (count_smaller(mid) < K)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> K;

	// �̺�Ž������ K��° �� ���ϱ�
	cout << binary_search(0, N * N);


	return 0;
}