//https://www.acmicpc.net/problem/1309
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int const MAX = 100000;
	int const mod = 9901;
	int D[MAX + 1];

	int n;
	cin >> n;

	/*
		D[0][0] : 사자 0마리
		D[0][1] : 사자 1번째 칸
		D[0][2] : 사자 2번째 칸  일때

		D[n][0] = D[n - 1][0] + D[n - 1][1] D[n - 1][2]
		D[n][1] = D[n - 1][0] + D[n - 1][2]
		D[n][2] = D[n - 1][0] + D[n - 1][1]

		--> Sum(D[n][i]) = 2 * Sum(D[n - 1][i]) + D[n][0]
		--> Sum(D[n][i]) = 2 * Sum(D[n - 1][i]) + Sum(D[n - 2][i])
		
		==> D[n] = 2 * D[n - 1] + D[n - 2]
	*/

	D[1] = 3;
	D[2] = 7;
	for (int i = 3; i <= n; i++)
	{
		D[i] = (2 * D[i - 1] + D[i - 2]) % mod;
	}

	cout << D[n];

	return 0;
}