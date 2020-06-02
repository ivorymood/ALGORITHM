//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int N, int K)
{
	int MAX = K * 2;
	// �̵�Ƚ���� �޸������̼� �� time ���͸� �ִ밪���� �ʱ�ȭ
	vector<int> time(MAX + 1, numeric_limits<int>::max());
	
	// �����̵��� �ȱ⸦ �����ϱ� ���� 2���� ť ����
	queue<int> q;
	queue<int> next_q;

	// ť�� ������ġ push, time[������ġ]�� 0���� �ʱ�ȭ
	q.push(N);
	time[N] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// K�� �����ϸ� �̵�Ƚ�� ��ȯ �� ����
		if (now == K)
		{
			return time[now];
		}

		// 2�� �����̵�, �ڷ� ��ĭ �ȱ�, ������ ��ĭ �ȱ� ������ ���� (ȿ����)
		int next[] = { now * 2, now - 1, now + 1 };
		for (int i = 0; i < 3; ++i)
		{
			// ������ ����ų�, ������ �̵�Ƚ���� �� �̵�Ƚ������ ���ų� �۴ٸ� pass
			if (next[i] < 0 || next[i] > MAX || time[next[i]] <= time[now])
			{
				continue;
			}

			// 2�� �����̵� �϶�
			if (i == 0)
			{
				/*
					���� �̵�Ƚ�� + 0, ���� ť�� push
					--> �̵�Ƚ���� ���� ������ ������־�� ��
				*/
				time[next[i]] = time[now];
				q.push(next[i]);
			}
			// �ȱ� �� ��
			else
			{
				// ���� �̵�Ƚ�� + 1, ���� ť�� push
				time[next[i]] = time[now] + 1;
				next_q.push(next[i]);
			}
		}

		/*
			���� ť�� ����ٸ� ���� ť�� swap
			(= �����̵� �۾� ����, �ȱ� �۾��� ���߿� �����ϰ� ��)
		*/
		if (q.empty())
		{
			q.swap(next_q);
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

	// K�� N���� ���ų� ������ : �ڷ� �ȱ⸸ ������.
	if (N >= K)
	{
		cout << N - K;
	}
	// K�� N���� ũ�� : �ʺ�켱 Ž������ �ּ��̵�Ƚ�� ���ϱ�
	else
	{
		cout << bfs(N, K);
	}

	return 0;
}