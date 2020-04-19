//https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10;
	int D[MAX + 1] = { 1, 1, 2, };

	// Á¡È­½Ä : D[n] = D[n - 1] + D[n - 2] + D[n - 3]
	for (int i = 3; i <= MAX; i++)
	{
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}

	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		int n;
		cin >> n;
		cout << D[n] << '\n';
	}

	return 0;
}