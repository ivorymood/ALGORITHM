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

		// 목표점에 도착하면 cost[목표점] 반환 후 종료
		if (q_now == K)
		{
			return cost[q_now];
		}

		// -1, +1, *2 의 위치로 이동 가능하고 아직 방문하지 않았으면  
		// cost배열에 이동횟수 저장 후 큐에 push
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

	// 너비우선탐색으로 이동가능한 지점에 이동횟수를 저장하며 목표까지 이동
	cout << bfs(N, K);

	return 0;
}