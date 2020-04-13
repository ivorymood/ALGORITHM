//https://www.acmicpc.net/problem/10950
#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	while (num-- > 0) {
		int A, B;
		cin >> A >> B;
		cout << A + B << '\n';
	}

	return 0;
}