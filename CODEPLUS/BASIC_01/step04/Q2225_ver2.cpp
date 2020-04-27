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
	long long S[MAX + 1] = { 1,};

	int N, K;
	cin >> N >> K;

	/*
	점화식
		D[K][N] : 0 ~ N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
		D[K][N] = D[K - 1][N] + D[K][N - 1]
		
		S[N] : D[K][N] 이라 하면
		
		S[N] = k번 sum(S[N] + S[N - 1])
	*/
	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			S[j] += S[j - 1];
			S[j] %= mod;
		}
	}

	cout << S[N];

	return 0;
}