//https://www.acmicpc.net/problem/11653
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	// N의 소인수 찾기 (단, N이 소수가 아닐때)
	for (int i = 2; i * i <= N; i++)
	{
		while (N % i == 0)
		{
			cout << i << '\n';
			N /= i;
		}
	}

	// 마지막 남은 소수 N 출력
	if (N > 1)
	{
		cout << N;
	}

	return 0;
}