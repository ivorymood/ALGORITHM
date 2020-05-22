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

		// x�� �߰�
		if (cmd == "add")
		{
			cin >> x;
			S |= (1 << --x);
		}
		// x�� ����
		else if (cmd == "remove")
		{
			cin >> x;
			S &= ~(1 << --x);
		}
		// x�� �˻�
		else if (cmd == "check")
		{
			cin >> x;
			cout << ((S & (1 << --x)) > 0) << '\n';
		}
		// x�� ��� (0�� 1��, 1�� 0����)
		else if (cmd == "toggle")
		{
			cin >> x;
			S ^= (1 << --x);
		}
		// ��ü ����
		else if (cmd == "all")
		{
			S = (1 << MAX) - 1;
		}
		// ������
		else if (cmd == "empty")
		{
			S = 0;
		}
	}

	return 0;
}