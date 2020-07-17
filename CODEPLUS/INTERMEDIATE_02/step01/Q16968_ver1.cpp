//https://www.acmicpc.net/problem/16968
#include <iostream>

using namespace std;

int get_next(char bfr, char now)
{
	int next = 0;
	if (now == 'c')
	{
		next = 26;
	}
	else
	{
		next = 10;
	}

	// 앞 문자와 중복되는 경우 제외
	if (bfr == now)
	{
		--next;
	}

	return next;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	string format;
	cin >> format;

	// 각 자리의 경우의 수를 구해서 곱하기
	int total = get_next(0, format[0]);
	for (int i = 1; i < format.size(); ++i)
	{
		total *= get_next(format[i - 1], format[i]);
	}

	cout << total;

	return 0;
}