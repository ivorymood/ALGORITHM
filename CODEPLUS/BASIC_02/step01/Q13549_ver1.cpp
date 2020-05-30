//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int N, int K)
{
	int MAX = K * 2;
	// 이동횟수를 메모이제이션 할 time 벡터를 최대값으로 초기화
	vector<int> time(MAX + 1, numeric_limits<int>::max());
	
	// 순간이동과 걷기를 구분하기 위해 덱 선언
	deque<int> dq;
	
	// 덱에 시작위치 push, time[시작위치]를 0으로 초기화
	dq.push_back(N);
	time[N] = 0;

	while (!dq.empty())
	{
		int now = dq.front();
		dq.pop_front();

		// K에 도착하면 이동횟수 반환 및 종료
		if (now == K)
		{
			return time[now];
		}

		// 2배 순간이동, 뒤로 한칸 걷기, 앞으로 한칸 걷기 순으로 진행 (효율적)
		int next[] = { now * 2, now - 1, now + 1 };
		for (int i = 0; i < 3; ++i)
		{
			// 범위를 벗어나거나, 기존의 이동횟수가 새 이동횟수보다 같거나 작다면 pass
			if (next[i] < 0 || next[i] > MAX || time[next[i]] <= time[now])
			{
				continue;
			}

			// 2배 순간이동 일때
			if (i == 0)
			{
				/*
					현재 이동횟수 + 0, 덱의 앞으로 push
					--> 이동횟수가 적은 값부터 기록해주어야 함
				*/
				time[next[i]] = time[now];
				dq.push_front(next[i]);
			}
			// 걷기 일 때
			else
			{
				// 현재 이동횟수 + 1, 덱의 뒤로 push
				time[next[i]] = time[now] + 1;
				dq.push_back(next[i]);
			}
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