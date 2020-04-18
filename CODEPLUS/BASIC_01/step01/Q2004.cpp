//https://www.acmicpc.net/problem/2004
#include <iostream>
#include <algorithm>

using namespace std;

// num! 팩토리얼에서 div 개수 구하기
int get_factorial_div_cnt(int num, int div)
{
	int cnt = 0;
	for (long long i = div; num / i >= 1; i *= div)
	{
		cnt += num / i;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	// nCm 조합에서는 인수 2와 5 중 어떤 것의 개수가 더 큰지 알 수 없다.
	// 각각 계산 후 더 적은 것의 개수가 0의 개수와 같다. 
	int cnt_2 = get_factorial_div_cnt(n, 2) - get_factorial_div_cnt(m, 2) - get_factorial_div_cnt(n - m, 2);
	int cnt_5 = get_factorial_div_cnt(n, 5) - get_factorial_div_cnt(m, 5) - get_factorial_div_cnt(n - m, 5);

	cout << min(cnt_2, cnt_5);

	return 0;
}