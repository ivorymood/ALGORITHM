//https://www.acmicpc.net/problem/11057
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int mod = 10007;
	const int MAX = 1000;
	int D[MAX + 1][10] = {1, };

	int N;
	cin >> N;

	/*
		점화식
		
		D[i][j] = 길이 i 일때, j로 끝나는 오르막수 
		D[i][j] = sum(D[i][k])  (단, 0 <= k <= j)
	*/
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				D[i][j] += D[i - 1][k];
			}
			D[i][j] %= mod;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += D[N][i];
	}
	cout << sum % mod;

	return 0;
}