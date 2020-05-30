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
	
	// <위치, 이동횟수> 
	// 순간이동과 걷기를 구분하기 위해 2개의 큐 선언
	queue<pair<int, int>> q;
	queue<pair<int, int>> next_q;

	// 큐에 {시작위치, 0 }push, 시작 위치 방문 체크
	q.push({N, 0});
	visit[N] = true;

	while (!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		printf("now : %d  time : %d\n", now, time);

		// K에 도착하면 이동횟수 반환 및 종료
		if (now == K)
		{
			return time;
		}

		// 2배 순간이동, 뒤로 한칸 걷기, 앞으로 한칸 걷기 순으로 진행 (효율적)
		int next[] = { now * 2, now - 1, now + 1 };
		for (int i = 0; i < 3; ++i)
		{
			// 범위를 벗어나거나, 이미 방문한 적이 있는 위치면 pass
			if (next[i] < 0 || next[i] > MAX || visit[next[i]] == true)
			{
				continue;
			}

			visit[next[i]] = true;

			// 2배 순간이동 일때
			if (i == 0)
			{
				/*
					현재 큐에 <2배 위치, 현재 이동횟수> push
					--> 이동횟수가 적은 값부터 기록해주어야 하므로
				*/
				q.push({ next[i], time});
			}
			// 걷기 일 때
			else
			{
				// 다음 큐에 <+1/-1 위치, 현재 이동횟수 + 1> push
				next_q.push({ next[i], time + 1 });
			}
		}

		/*
			현재 큐가 비었다면 다음 큐와 swap
			(= 순간이동 작업 먼저, 걷기 작업을 나중에 수행하게 됨)
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

	// K가 N보다 같거나 작으면 : 뒤로 걷기만 가능함.
	if (N >= K)
	{
		cout << N - K;
	}
	// K가 N보다 크면 : 너비우선 탐색으로 최소이동횟수 구하기
	else
	{
		cout << bfs(N, K);
	}

	return 0;
}