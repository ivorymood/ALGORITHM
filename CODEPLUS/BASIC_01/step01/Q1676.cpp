//https://www.acmicpc.net/problem/1676
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// 10 = 2 * 5 인데, 
	// 2의 배수보다 5의 배수가 더 적으므로
	// 인수 중 5의 개수만 세면 된다.
	int cnt_5 = 0;
	for (int i = 5; n / i >= 1; i *= 5)
	{
		cnt_5 += n / i;
	}
	cout << cnt_5;

	return 0;
}