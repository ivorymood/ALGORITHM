//https://www.acmicpc.net/problem/1697
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100000;
int cost[MAX + 1];

bool inline possible(int n)
{
	return !(n < 0 || n > MAX);
}

int bfs(int N, int K)
{
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int q_now = q.front();
		q.pop();

		// ��ǥ���� �����ϸ� cost[��ǥ��] ��ȯ �� ����
		if (q_now == K)
		{
			return cost[q_now];
		}

		// -1, +1, *2 �� ��ġ�� �̵� �����ϰ� ���� �湮���� �ʾ�����  
		// cost�迭�� �̵�Ƚ�� ���� �� ť�� push
		if (possible(q_now - 1) && cost[q_now - 1] == 0)
		{
			cost[q_now - 1] = cost[q_now] + 1;
			q.push(q_now - 1);
		}
		if (possible(q_now + 1) && cost[q_now + 1] == 0)
		{
			cost[q_now + 1] = cost[q_now] + 1;
			q.push(q_now + 1);
		}
		if (possible(q_now * 2) && cost[q_now * 2] == 0)
		{
			cost[q_now * 2] = cost[q_now] + 1;
			q.push(q_now * 2);
		}
	}
	return abs(N - K);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	// �ʺ�켱Ž������ �̵������� ������ �̵�Ƚ���� �����ϸ� ��ǥ���� �̵�
	cout << bfs(N, K);

	return 0;
}