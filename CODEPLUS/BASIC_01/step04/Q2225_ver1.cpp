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
	��ȭ��
		D[K][N] : 0 ~ N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ��
		N = (K-1 ���� ��) + L  (�̶�, 0 <= L <= N )

		D[K][N] = (D[K - 1][0] + ... + D[K - 1][N - 1]) + D[K - 1][N]
				= D[K][N - 1] + D[K - 1][N]

		--> D[K][N] = D[K][N - 1] + D[K - 1][N]
	*/
	for (int i = 1; i <= K; i++)
	{
		D[i][0] = 1;
		for (int j = 1; j <= N; j++)
		{
			D[i][j] = (D[i][j - 1] + D[i - 1][j]) % mod;
		}
	}

	cout << D[K][N];

	return 0;
}