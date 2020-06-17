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

	// 사전순 출력을 위한 연산자 순서
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
			// 연산 결과가 0 이상 10^9 이하이고, 전에 방문한적이 없다면
			long long next = calculate(n, ops[i]);
			if (next >= 0 && visit.count(next) == 0)
			{
				// set에 push해서 방문체크
				visit.insert(next);
				// 큐에 {다음숫자, 이제까지의 문자열 + 새 연산자} push 
				q.push({ next, str + ops[i] });
			}
		}
	}

	// s ~ t로 변환 불가능할 때 
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