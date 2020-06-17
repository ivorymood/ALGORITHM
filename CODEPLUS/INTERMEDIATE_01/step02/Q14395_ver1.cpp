//https://www.acmicpc.net/problem/14395
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const long long limit = 1000000000LL;

long long calculate(long long n, char c)
{
	long long res = -1;

	if (c == '*')
	{
		res = n * n;
	}
	else if (c == '+')
	{
		res = n + n;
	}
	else if (c == '-')
	{
		res = n - n;
	}
	else if (n > 0 && c == '/')
	{
		res = n / n;
	}

	if (res > limit)
	{
		res = -1;
	}
	return res;
}

void bfs(long long s, long long t)
{
	queue<pair<long long, string>> q;
	set<long long> visit;
	q.push({ s, "" });
	visit.insert(s);

	// ������ ����� ���� ������ ����
	char ops[] = { '*', '+', '-', '/' };

	while (!q.empty())
	{
		long long n = q.front().first;
		string str = q.front().second;
		q.pop();

		if (n == t)
		{
			if (str.size() == 0)
			{
				cout << 0;
			}
			else
			{
				cout << str;
			}
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			// ���� ����� 0 �̻� 10^9 �����̰�, ���� �湮������ ���ٸ�
			long long next = calculate(n, ops[i]);
			if (next >= 0 && visit.count(next) == 0)
			{
				// set�� push�ؼ� �湮üũ
				visit.insert(next);
				// ť�� {��������, ���������� ���ڿ� + �� ������} push 
				q.push({ next, str + ops[i] });
			}
		}
	}

	// s ~ t�� ��ȯ �Ұ����� �� 
	cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long s, t;
	cin >> s >> t;

	bfs(s, t);

	return 0;
}