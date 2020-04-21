//https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

const int MAX = 10;
int D[MAX + 1] = {1, };

// 점화식 : D[n] = D[n - 1] + D[n - 2] + D[n - 3]
int get_123_sum(int n)
{
	if (D[n] > 0)
	{
		return D[n];
	}
	if (n <= 2)
	{
		return D[n] = n;
	}

	return D[n] = get_123_sum(n - 1) + get_123_sum(n - 2)+ get_123_sum(n - 3);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		int n;
		cin >> n;

		get_123_sum(n);

		cout << D[n] << '\n';
	}

	return 0;
}