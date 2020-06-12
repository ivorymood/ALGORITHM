//https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX = 100;

int bfs(vector<int> &SnL, vector<int> &min_cnt)
{
	// 1���� ����
	queue<int> q;
	q.push(1);
	min_cnt[1] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// 100�� �����ϸ� �ּ� �̵�Ƚ�� ����
		if (now == MAX)
		{
			return min_cnt[now];
		}

		// �ֻ��� ������
		for (int i = 1; i <= 6; ++i)
		{
			// �������� : ��ٸ�/�� �ݿ��� ���� + �ֻ��� �� (100 �ʰ��� �̵�X)
			int next = (SnL[now] > 0) ? SnL[now] + i : now + i;
			if (next > 100)
			{
				continue;
			}

			// �̹� �ּҰ��� �Ű����ٸ� �ǳʶٱ�
			if (min_cnt[next] > min_cnt[now] + 1)
			{
				min_cnt[next] = min_cnt[now] + 1;
				q.push(next);
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

	// �Է�
	int N, M;
	cin >> N >> M;
	vector<int> SnL(MAX + 1);
	for (int i = 0; i < N + M; ++i)
	{
		int now, next;
		cin >> now >> next;
		SnL[now] = next;
	}

	// �̵�Ƚ�� �ּҰ��� �����ϱ� ���� ����
	vector<int> min_cnt(MAX + 1, numeric_limits<int>::max());

	// 1 ~ 100���� �ּ� �̵�Ƚ�� ���
	cout << bfs(SnL, min_cnt);

	return 0;
}