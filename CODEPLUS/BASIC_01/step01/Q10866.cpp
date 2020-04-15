//https://www.acmicpc.net/problem/10866
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	cin.ignore();

	deque<int> dq;

	while (cnt--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push_front")
		{
			int n;
			cin >> n;
			dq.push_front(n);
		}
		else if (cmd == "push_back")
		{
			int n;
			cin >> n;
			dq.push_back(n);
		}
		else if (cmd == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else if (cmd == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		else if (cmd == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << (dq.empty() ? 1 : 0) << '\n';
		}
		else if (cmd == "front")
		{
			cout << ((dq.empty()) ? -1 : dq.front()) << '\n';
		}
		else if (cmd == "back")
		{
			cout << (dq.empty() ? -1 : dq.back()) << '\n';
		}
	}

	return 0;
}