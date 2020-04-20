//https://www.acmicpc.net/problem/1699
#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 100000;
int cnt[MAX + 1];

// DP로 풀어야 하는 이유: D[32] = 2 같은 반례가 있기 때문에

/*
	D[i] : i를 제곱수의 합으로 나타냈을 때, 최소 항의 개수

	점화식 : D[i] = min(D[i - j^2]) + 1
*/
int get_min_pow_sum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (cnt[n] > 0)
	{
		return cnt[n];
	}

	int min = n;
	for (int i = 1; i * i <= n; i++)
	{
		if (n - i * i >= 0)
		{
			int tmp = get_min_pow_sum(n - i * i) + 1;
			min = (min > tmp) ? tmp : min;
		}
	}
	return cnt[n] = min;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	get_min_pow_sum(n);

	cout << cnt[n];

	return 0;
}