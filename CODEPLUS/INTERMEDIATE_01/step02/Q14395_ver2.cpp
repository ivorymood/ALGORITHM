//https://www.acmicpc.net/problem/14395
#include <iostream>
#include <queue>
#include <map>

using namespace std;

const long long limit = 1000000000LL;
map<long long, long long> bf_idx;
map<long long, char> op;

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

void print(int n)
{
	// ���� �ε����� -1 �϶����� print�Լ� ���ȣ�� & ���
	if (bf_idx[n] == -1)
	{
		return;
	}

	print(bf_idx[n]);

	cout << op[n];
}

bool bfs(long long s, long long t)
{
	queue<long long> q;
	q.push(s);
	bf_idx[s] = -1;

	// ������ ����� ���� ������ ����
	char ops[] = { '*', '+', '-', '/' };

	while (!q.empty())
	{
		long long n = q.front();
		q.pop();

		if (n == t)
		{
			return true;
		}

		for (int i = 0; i < 4; ++i)
		{
			// ���� ����� 0 �̻� 10^9 �����̰�, ���� �湮������ ���ٸ�
			long long next = calculate(n, ops[i]);
			if (next >= 0 && bf_idx.find(next) == bf_idx.end())
			{
				// next�� ���� �ε��� : �������
				bf_idx[next] = n;
				// ���� ���� ~ next�� �ʿ��� ������
				op[next] = ops[i];
				q.push(next);
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long s, t;
	cin >> s >> t;

	// s�� t�� ���� ��
	if (s == t)
	{
		cout << 0;
	}
	// s ~ t�� ��ȯ ������ ��
	else if (bfs(s, t))
	{
		print(t);
	}
	// s ~ t�� ��ȯ �Ұ����� �� 
	else
	{
		cout << -1;
	}

	return 0;
}