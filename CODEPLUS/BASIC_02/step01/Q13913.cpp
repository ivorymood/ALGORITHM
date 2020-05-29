//https://www.acmicpc.net/problem/13913
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int cost[MAX + 1];
int bf_idx[MAX + 1];

bool possible(int n)
{
	return !(n < 0 || n > MAX);
}

// next�� �̵� �����ϸ� ť�� push
// cost�� bf_idx�迭�� ���� �̵�Ƚ��, ���� ��ġ ����
void check(queue<int> &q, int next, int now)
{
	if (possible(next) && cost[next] == 0)
	{
		cost[next] = cost[now] + 1;
		bf_idx[next] = now;
		q.push(next);
	}
}

int bfs(int N, int K)
{
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// ��ǥ���� �����ϸ� cost[��ǥ��] ��ȯ �� ����
		if (now == K)
		{
			return cost[now];
		}

		// -1, +1, *2�� ��ġ�� �̵������ϰ� ���� �湮���� �ʾ�����
		// cost, bf_idx �迭 ���� �� ť�� push
		check(q, now - 1, now);
		check(q, now + 1, now);
		check(q, now * 2, now);
	}
	return abs(N - K);
}

// bf_idx�迭�� bf���� �������� ���
void print_order(int N, int bf)
{
	if (bf != N)
	{
		print_order(N, bf_idx[bf]);
	}
	
	cout << bf << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	// �ּ� �̵�Ƚ�� ���
	cout << bfs(N, K) << '\n';
	// �̵� ��� ���
	print_order(N, K);

	return 0;
}