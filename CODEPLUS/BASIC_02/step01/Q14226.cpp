//https://www.acmicpc.net/problem/14226
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int time[MAX + 1][MAX + 1];

void check(queue<pair<int, int>> &q, int S, int next, int next_clip, int now)
{
	// ������ ����ų�, �̹� ���� �����ϴ� ��� ����
	if (next < 0 || next > S || time[next][next_clip] != 0)
	{
		return;
	}
	// ����Ƚ�� + 1
	time[next][next_clip] = now + 1;
	// ť�� <���� �� ȭ�鹮�� ����, Ŭ������ ���� ����> push
	q.push(make_pair(next, next_clip));
}

// �ʺ�켱 Ž������ S�� ������ ������ ����Ƚ���� time �迭�� �����س�����.
int bfs(int S)
{
	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		int now = q.front().first;
		int bf_clip = q.front().second;
		q.pop();

		// ȭ�� ���ڰ����� S���� �Ǹ� ����Ƚ�� ��ȯ �� ����
		if (now == S)
		{
			return time[now][bf_clip];
		}

		/*
			����     : <���� ȭ�鹮��       , ���� ȭ�鹮��>
			�ٿ��ֱ� : <���� ȭ�鹮�� + Ŭ��, Ŭ��>
			����     : <���� ȭ�鹮�� -1    , Ŭ��>
		*/
		check(q, S, now          , now    , time[now][bf_clip]);
		check(q, S, now + bf_clip, bf_clip, time[now][bf_clip]);
		check(q, S, now - 1      , bf_clip, time[now][bf_clip]);
	}

	return S + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int S;
	cin >> S;
	cout << bfs(S);

	return 0;
}