//https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, K;
	cin >> N >> K;
	vector<int> coins(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> coins[i];
	}

	// K보다 작은 최대 액수의 동전을 가장 많이 써나간다.  
	int cnt = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		// cnt += i번째 동전을 최대로 쓸수 있는 개수
		cnt += K / coins[i];
		
		// K -= i번째 동전을 최대로 쓴 금액
		K %= coins[i];
	}

	cout << cnt;

	return 0;
}