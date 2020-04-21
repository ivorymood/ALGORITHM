//https://www.acmicpc.net/problem/17087
#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, S;
	cin >> N >> S;

	// 동생과 수빈이의 위치 차이를 저장
	vector<int> sister_gap(N);
	for (int i = 0; i < N; i++)
	{
		cin >> sister_gap[i];
		sister_gap[i] = (S - sister_gap[i] > 0) ? S - sister_gap[i] : sister_gap[i] - S;
	}

	// 개별 차이값들의 최대공약수 계산
	int gcd = sister_gap[0];
	for (int i = 1; i < N; i++)
	{
		gcd = GCD(gcd, sister_gap[i]);
	}

	cout << gcd;

	return 0;
}