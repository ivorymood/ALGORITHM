//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int N, int K)
{
	int MAX = K * 2;
	vector<int> visit(MAX + 1);
	
	// <��ġ, �̵�Ƚ��> 
	// �����̵��� �ȱ⸦ �����ϱ� ���� 2���� ť ����
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;

	// ť�� {������ġ, 0 }push, ���� ��ġ �湮 üũ
	q.push({N, 0});
	visit[N] = true;

	while (!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		printf("now : %d  time : %d\n", now, time);

		// K�� �����ϸ� �̵�Ƚ�� ��ȯ �� ����
		if (now == K)
		{
			return time;
		}

		// 2�� �����̵�, �ڷ� ��ĭ �ȱ�, ������ ��ĭ �ȱ� ������ ���� (ȿ����)
		int next[] = { now * 2, now - 1, now + 1 };
		for (int i = 0; i < 3; ++i)
		{
			// ������ ����ų�, �̹� �湮�� ���� �ִ� ��ġ�� pass
			if (next[i] < 0 || next[i] > MAX || visit[next[i]] == true)
			{
				continue;
			}

			visit[next[i]] = true;

			// 2�� �����̵� �϶�
			if (i == 0)
			{
				/*
					���� ť�� <2�� ��ġ, ���� �̵�Ƚ��> push
					--> �̵�Ƚ���� ���� ������ ������־�� �ϹǷ�
				*/
				q.push({ next[i], time});
			}
			// �ȱ� �� ��
			else
			{
				// ���� ť�� <+1/-1 ��ġ, ���� �̵�Ƚ�� + 1> push
				next_q.push({ next[i], time + 1 });
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