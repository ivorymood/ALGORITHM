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

// next로 이동 가능하면 큐에 push
// cost와 bf_idx배열에 각각 이동횟수, 현재 위치 저장
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

		// 목표점에 도착하면 cost[목표점] 반환 후 종료
		if (now == K)
		{
			return cost[now];
		}

		// -1, +1, *2의 위치로 이동가능하고 아직 방문하지 않았으면
		// cost, bf_idx 배열 저장 후 큐에 push
		check(q, now - 1, now);
		check(q, now + 1, now);
		check(q, now * 2, now);
	}
	return abs(N - K);
}

// bf_idx배열을 bf부터 역순으로 출력
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

	// 최소 이동횟수 출력
	cout << bfs(N, K) << '\n';
	// 이동 경로 출력
	print_order(N, K);

	return 0;
}