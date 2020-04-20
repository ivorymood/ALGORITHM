//https://www.acmicpc.net/problem/2225
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 200;
	const int mod = 1000000000;
	long long D[MAX + 1][MAX + 1] = { 1, };
	
	int N, K;
	cin >> N >> K;
	
	/*
		D[K][N] : 0 ~ N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
	
		N = (K-1 개의 수) + L  (이때, 0 <= L <= N )

		--> 점화식 : D[K][N] = Sum(D[K - 1][N - L])
	*/
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				D[i][j] += D[i - 1][j - l];
				D[i][j] %= mod;
			}
		}
	}

	cout << D[K][N];

	return 0;
}