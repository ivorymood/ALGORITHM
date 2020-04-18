//https://www.acmicpc.net/problem/10872
#include <iostream>

using namespace std;

int get_factorial(int num)
{
	if (num == 0)
	{
		return 1;
	}
	
	return num * get_factorial(num - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << get_factorial(n);
	
	return 0;
}