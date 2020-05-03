//https://www.acmicpc.net/problem/6064
#include <iostream>

using namespace std;

int calendar(int M, int N, int x, int y)
{
	int MAX = M * N;

	// x에서부터 M씩 건너뛰며 계산
	// --> O(N)
	for (int i = x; i <= MAX; i += M)
	{
		if (i % N == y % N)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		cout << calendar(M, N, x, y) << '\n';
	}

	return 0;
}