//https://www.acmicpc.net/problem/2745
#include <iostream>
#include <cmath>

using namespace std;

int nbase_to_decimal(string n, int x)
{
	int decimal = 0;
	
	// ABC(x) = A * x^2 + B * X^1 + C
	for (int i = 0; i < n.size(); i++)
	{
		decimal *= x;
		decimal += (n[i] >= 'A') ? n[i] - 'A' + 10 : n[i] - '0';
	}
	return decimal;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string N;
	int B;
	cin >> N;
	cin >> B;

	cout << nbase_to_decimal(N, B);

	return 0;
}