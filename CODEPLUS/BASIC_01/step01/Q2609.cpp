//https://www.acmicpc.net/problem/2609
#include <iostream>

using namespace std;

/*
	유클리드 호제법
	a % b = r 일때, GCD(a, b) = GCD(b, r)
*/
int GCD(int A, int B)
{
	if (B != 0)
	{
		return GCD(B, A % B);
	}
	return A;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;

	int gcd = GCD(A, B);
	int lcm = A * B / gcd;

	cout << gcd << '\n' << lcm;

	return 0;
}

