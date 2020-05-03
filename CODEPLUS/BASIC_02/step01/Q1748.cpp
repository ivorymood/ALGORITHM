//https://www.acmicpc.net/problem/1748
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	
	int sum = 0;
	for (int start = 1, digit = 1; start <= num; start *= 10, digit++)
	{
		int end = start * 10 - 1;
		end = (end > num) ? num : end;

		sum += (end - start + 1) * digit;
	}

	cout << sum;

	return 0;
}