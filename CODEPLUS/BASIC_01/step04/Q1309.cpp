//https://www.acmicpc.net/problem/1309
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int mod = 9901;
	const int MAX = 100000;
	int D[MAX + 1];
	int S[MAX + 1];

	int N;
	cin >> N;

	/*
		n개의 줄에 사자를 배치하는 전체 경우의 수 S[n]는
		i번째(1 <= i <= n) 줄까지만 사자가 위치하는 경우의 수의 합이다.
		--> S[n] : D[n] + D[n - 1] + ... + D[1] 
		

		D[i] : i번째까지만 사자가 있는 경우.
				(단, i번째에는 사자가 반드시 있고, 
				1 ~ i-1번째에는 사자가 있을수도 있고 없을 수도 있다.)

		D[i] 값
		= i - 1번째까지만 사자가 위치할 경우
		+ (i - 2번째까지만 사자가 위치할 경우) * 2
		...
		+ (1번째까지만 사자가 위치할 경우) * 2

		k번째(단, 1 <= k <= i - 2) 경우 값에 2를 곱하는 이유
		: i - 1번째 줄은 i번째 사자 위치의 제약을 받지만
		k번째 줄은 k + 1번째 줄에 사자가 없다. 
		따라서 D[k]는 i번째에서 사자가 각각 왼쪽/오른쪽 위치하는 경우의 수 2를 곱해준다. 
		

	점화식
		--> D[i] = D[i - 1] + 2 * (D[i - 2] + ... + D[1])
				 = D[i - 1] + 2 * S[i - 2]
	*/

	D[0] = 1;
	S[0] = 1;
	D[1] = 2;
	S[1] = D[1] + S[0];
	for (int i = 2; i <= N; i++)
	{
		D[i] = (D[i - 1] + 2 * S[i - 2]) % mod;
		S[i] = (D[i] + S[i - 1]) % mod;
	}

	cout << S[N];

	return 0;
}