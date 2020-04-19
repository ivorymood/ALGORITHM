//https://www.acmicpc.net/problem/11727
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	const int DIV = 10007;
	const int MAX = 1000;
	int D[MAX + 1];

	D[0] = 1;
	D[1] = 1;

	// Á¡È­½Ä : D[n] = D[n - 1] + D[n - 2] * 2;
	for (int i = 2; i <= n; i++)
	{
		D[i] = (D[i - 1] + D[i - 2] * 2) % DIV;
	}

	cout << D[n];

	return 0;
}