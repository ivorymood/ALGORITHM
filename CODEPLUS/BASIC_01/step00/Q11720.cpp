//https://www.acmicpc.net/problem/11720
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	while (n-- > 0)
	{
		char c;
		cin >> c;
		
		sum += c - '0';
	}

	cout << sum;

	return 0;
}