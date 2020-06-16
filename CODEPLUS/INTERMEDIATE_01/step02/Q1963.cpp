//https://www.acmicpc.net/problem/1963
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 10000;
bool no_prime[MAX];
bool visit[MAX];

void sieve_of_eratosthenes()
{
	for (int i = 2; i < MAX; ++i)
	{
		if (!no_prime[i])
		{
			for (int j = 2; j * i < MAX; ++j)
			{
				no_prime[j * i] = true;
			}
		}
	}
}

int bfs(int start, int end)
{
	struct info {
		int p_num, cnt;
	};

	// ���� �Ҽ� push
	queue<info> q;
	q.push({start, 0});
	visit[start] = true;

	// 4�ڸ� ������ �� �ڸ� ����ġ
	int w[] = {1000, 100, 10, 1};

	while (!q.empty())
	{
		int p_num = q.front().p_num;
		int cnt = q.front().cnt;
		q.pop();

		// �� �Ҽ��� �����ϸ� ��ȯȽ�� ��ȯ
		if (p_num == end)
		{
			return cnt;
		}

		// 4�ڸ� ������ �տ������� ���ڸ��� Ž��
		for (int i = 0; i < 4; ++i)
		{
			/*
				base : i��° �ڸ� ���ڸ� 0���� ���� ����
				ex) ���� 1373�̰� i�� 1�� �� --> base : 1073
			*/
			int base = p_num - ((p_num / w[i]) % 10) * w[i];
			for (int j = 0; j < 10; ++j)
			{
				/*
					n : i��° �ڸ� ���ڸ� 0 ~ 9�� �ϳ��� ��ȯ�� ��
					ex) base�� 1073 �̰� j�� 7�̸� --> n : 1773
				*/
				int n = j * w[i] + base;
				
				// �������ڿ� ���ų�, 1000�̸��̰ų�, �Ҽ��� �ƴϰų�, �̹� �湮������
				if (n == p_num || n < 1000 || no_prime[n] || visit[n])
				{
					continue;
				}

				// �湮üũ �� ��ȯ Ƚ�� + 1�� ť�� push
				visit[n] = true;
				q.push({ n, cnt + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �����佺�׳׽��� ü�� no_prime�迭�� �Ҽ��� �ƴ� ������ true üũ
	sieve_of_eratosthenes();

	int T;
	cin >> T;
	while(T--)
	{
		int start, end;
		cin >> start >> end;

		// visit �迭 0 �ʱ�ȭ
		memset(visit, 0, sizeof(visit));

		// bfs�� ���� �Ҽ����� �� �Ҽ����� ��ȯ�� �ʿ��� Ƚ�� ���ϱ�
		int cnt = bfs(start, end);
		if (cnt < 0)
		{
			cout << "Impossible\n";
		}
		else
		{
			cout << cnt << '\n';
		}
	}

	return 0;
}