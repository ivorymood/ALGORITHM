//https://www.acmicpc.net/problem/2193
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 90;
	long long S[MAX + 1] = {0, 1, };

	int n;
	cin >> n;

	/*
	D[N][i] : i로 끝나는 N자리의 이친수라 할때,

			S[N] = D[N][0] + D[N][1]
			D[N][0] = D[N - 1][0] + D[N - 1][1]				  = S[N - 1]
			D[N][1] = D[N - 1][0] = D[N - 2][0] + D[N - 2][1] = S[N - 2]

	--> 점화식 : S[N] = S[N - 1] + S[N - 2]
	*/
	for (int i = 2; i <= n; i++)
	{
		S[i] = S[i - 1] + S[i - 2];
	}

	cout << S[n];

	return 0;
}