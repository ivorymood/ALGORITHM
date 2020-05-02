//https://www.acmicpc.net/problem/1476
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int E, S, M;
	cin >> E >> S >> M;

	int i = 1, e = 1, s = 1, m = 1;
	while (!(e == E && s == S && m == M))
	{
		i++;
		e++;
		s++;
		m++;

		if (e > 15)
		{
			e = 1;
		}
		if (s > 28)
		{
			s = 1;
		}
		if (m > 19)
		{
			m = 1;
		}
	}

	cout << i;

	return 0;
}