//https://www.acmicpc.net/problem/1699
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	const int MAX = 100000;
	int cnt[MAX + 1];

	/*
		D[i] : i를 제곱수의 합으로 나타냈을 때, 최소 항의 개수
		점화식 : D[i] = min(D[i - j^2]) + 1
	*/
	cnt[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			if (cnt[i] > cnt[i - j * j] + 1)
			{
				cnt[i] = cnt[i - j * j] + 1;
			}
		}
	}
	
	cout << cnt[n];

	return 0;
}