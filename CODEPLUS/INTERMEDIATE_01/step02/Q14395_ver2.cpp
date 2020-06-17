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
	// 이전 인덱스가 -1 일때까지 print함수 재귀호출 & 출력
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

	// 사전순 출력을 위한 연산자 순서
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
			// 연산 결과가 0 이상 10^9 이하이고, 전에 방문한적이 없다면
			long long next = calculate(n, ops[i]);
			if (next >= 0 && bf_idx.find(next) == bf_idx.end())
			{
				// next의 이전 인덱스 : 현재숫자
				bf_idx[next] = n;
				// 현재 숫자 ~ next에 필요한 연산자
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

	// s와 t가 같을 때
	if (s == t)
	{
		cout << 0;
	}
	// s ~ t로 변환 가능할 때
	else if (bfs(s, t))
	{
		print(t);
	}
	// s ~ t로 변환 불가능할 때 
	else
	{
		cout << -1;
	}

	return 0;
}