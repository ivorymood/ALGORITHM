//https://www.acmicpc.net/problem/15988
#include <iostream>

using namespace std;

const int MAX = 1000000;
const long mod = 1000000009LL;
long long D[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	점화식
		D[n] : n을 1, 2, 3의 합으로 만드는 방법의 수
		D[n] = D[n - 1] (+ 1)
		     + D[n - 2] (+ 2)
			 + D{n - 3] (+ 3)
	*/
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= MAX; i++)
	{
		D[i] = (D[i - 1] + D[i - 2] + D[i - 3]) % mod;
	}

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << D[n] << '\n';
	}

	return 0;
}