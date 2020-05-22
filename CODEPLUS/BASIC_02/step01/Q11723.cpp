//https://www.acmicpc.net/problem/11723
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 20;
	int M, S = 0;
	cin >> M;
	while (M--)
	{
		string cmd;
		int x;
		cin >> cmd;

		// x를 추가
		if (cmd == "add")
		{
			cin >> x;
			S |= (1 << --x);
		}
		// x를 제거
		else if (cmd == "remove")
		{
			cin >> x;
			S &= ~(1 << --x);
		}
		// x를 검사
		else if (cmd == "check")
		{
			cin >> x;
			cout << ((S & (1 << --x)) > 0) << '\n';
		}
		// x를 토글 (0을 1로, 1을 0으로)
		else if (cmd == "toggle")
		{
			cin >> x;
			S ^= (1 << --x);
		}
		// 전체 집합
		else if (cmd == "all")
		{
			S = (1 << MAX) - 1;
		}
		// 공집합
		else if (cmd == "empty")
		{
			S = 0;
		}
	}

	return 0;
}