//https://www.acmicpc.net/problem/17103
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
bool isno_prime[MAX + 1];
vector<int> primes;

void do_prime_sieve()
{
	// 소수 벡터를 만들어야 하므로, 
	// 포문을 MAX범위까지 돌려야 한다.
	for (int i = 2; i <= MAX; i++)
	{
		if (!isno_prime[i])
		{
			primes.push_back(i);
			for (int j = 2; j * i <= MAX; j++)
			{
				isno_prime[j * i] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 에라토스테네스의 체
	do_prime_sieve();

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		int ptt_cnt = 0;

		for (int i = 0; i < primes.size(); i++)
		{
			// N = 소수1 + 소수2 (소수1 <= 소수2) 이므로
			// 소수1 <= N / 2
			if (primes[i] > N / 2)
			{
				break;
			}
			if (N - primes[i] >= 2 && isno_prime[N - primes[i]] == false)
			{
				ptt_cnt++;
			}
		}

		cout << ptt_cnt << '\n';
	}

	return 0;
}