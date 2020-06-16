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

	// 시작 소수 push
	queue<info> q;
	q.push({start, 0});
	visit[start] = true;

	// 4자리 숫자의 각 자리 가중치
	int w[] = {1000, 100, 10, 1};

	while (!q.empty())
	{
		int p_num = q.front().p_num;
		int cnt = q.front().cnt;
		q.pop();

		// 끝 소수에 도착하면 변환횟수 반환
		if (p_num == end)
		{
			return cnt;
		}

		// 4자리 숫자의 앞에서부터 한자리씩 탐색
		for (int i = 0; i < 4; ++i)
		{
			/*
				base : i번째 자리 숫자를 0으로 만든 숫자
				ex) 수가 1373이고 i가 1일 때 --> base : 1073
			*/
			int base = p_num - ((p_num / w[i]) % 10) * w[i];
			for (int j = 0; j < 10; ++j)
			{
				/*
					n : i번째 자리 숫자를 0 ~ 9로 하나씩 변환한 수
					ex) base가 1073 이고 j가 7이면 --> n : 1773
				*/
				int n = j * w[i] + base;
				
				// 원래숫자와 같거나, 1000미만이거나, 소수가 아니거나, 이미 방문했으면
				if (n == p_num || n < 1000 || no_prime[n] || visit[n])
				{
					continue;
				}

				// 방문체크 후 변환 횟수 + 1로 큐에 push
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

	// 에라토스테네스의 체로 no_prime배열에 소수가 아닌 수들을 true 체크
	sieve_of_eratosthenes();

	int T;
	cin >> T;
	while(T--)
	{
		int start, end;
		cin >> start >> end;

		// visit 배열 0 초기화
		memset(visit, 0, sizeof(visit));

		// bfs로 시작 소수부터 끝 소수까지 변환에 필요한 횟수 구하기
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