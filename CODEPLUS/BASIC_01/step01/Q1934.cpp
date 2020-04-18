//https://www.acmicpc.net/problem/1934
#include <iostream>

using namespace std;

int GCD(int A, int B)
{
	return (B != 0) ? GCD(B, A % B) : A;
}

int LCM(int A, int B)
{
	return A * B / GCD(A, B);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		int A, B;
		cin >> A >> B;
		cout << LCM(A, B) << '\n';
	}

	return 0;
}