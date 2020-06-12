//https://www.acmicpc.net/problem/16928
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX = 100;

int bfs(vector<int> &SnL, vector<int> &min_cnt)
{
	// 1부터 시작
	queue<int> q;
	q.push(1);
	min_cnt[1] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// 100에 도착하면 최소 이동횟수 리턴
		if (now == MAX)
		{
			return min_cnt[now];
		}

		// 주사위 던지기
		for (int i = 1; i <= 6; ++i)
		{
			// 다음숫자 : 사다리/뱀 반영된 숫자 + 주사위 눈 (100 초과는 이동X)
			int next = (SnL[now] > 0) ? SnL[now] + i : now + i;
			if (next > 100)
			{
				continue;
			}

			// 이미 최소값이 매겨졌다면 건너뛰기
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

	// 입력
	int N, M;
	cin >> N >> M;
	vector<int> SnL(MAX + 1);
	for (int i = 0; i < N + M; ++i)
	{
		int now, next;
		cin >> now >> next;
		SnL[now] = next;
	}

	// 이동횟수 최소값을 저장하기 위한 벡터
	vector<int> min_cnt(MAX + 1, numeric_limits<int>::max());

	// 1 ~ 100까지 최소 이동횟수 출력
	cout << bfs(SnL, min_cnt);

	return 0;
}