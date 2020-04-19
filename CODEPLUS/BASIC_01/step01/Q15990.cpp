//https://www.acmicpc.net/problem/15990
#include <iostream>

using namespace std;

const int DIV = 1000000009;
const int MAX = 100000;
int sum[MAX + 1][3 + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	 D[N][i] : N을 1, 2, 3의 합으로 나타내는 방법 중 i로 끝나는 경우의 수

	 점화식 : S[N]	= D[N][1] + D[N][2] + D[N][3]
					= D[N - 1][2] + D[N - 1][3]
					+ D[N - 2][1] + D[N - 2][3]
					+ D[N - 3][1] + D[N - 3][2]
	*/
	/*
	 케이스가 주어질 때마다 값을 구하는 것보다,
	 MAX만큼 미리 값을 구하고 케이스대로 출력하는 것이 시간효율적이다.
	*/
	sum[1][1] = 1;
	sum[2][2] = 1;
	sum[3][1] = 1;
	sum[3][2] = 1;
	sum[3][3] = 1;
	for (int i = 4; i <= MAX; i++)
	{
		sum[i][1] = (sum[i - 1][2] + sum[i - 1][3]) % DIV;
		sum[i][2] = (sum[i - 2][1] + sum[i - 2][3]) % DIV;
		sum[i][3] = (sum[i - 3][1] + sum[i - 3][2]) % DIV;
	}

	int cnt;
	cin >> cnt;

	while (cnt--)
	{
		int n;
		cin >> n;
		cout << ((sum[n][1] + sum[n][2]) % DIV + sum[n][3]) % DIV << '\n';
	}

	return 0;
}