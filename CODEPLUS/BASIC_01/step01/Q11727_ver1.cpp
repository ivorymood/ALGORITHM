//https://www.acmicpc.net/problem/11727
#include <iostream>

using namespace std;

const int DIV = 10007;
const int MAX = 1000;
int D[MAX + 1];

// 점화식 : D[n] = D[n - 1] + D[n - 2] * 2;
int make_tile(int n)
{
	if (D[n] > 0)
	{
		return D[n];
	}
	// 종료 조건
	if (n <= 1)
	{
		return D[n] = 1;
	}

	return D[n] = (make_tile(n - 1) + make_tile(n - 2) * 2) % DIV;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	make_tile(n);

	cout << D[n];

	return 0;
}