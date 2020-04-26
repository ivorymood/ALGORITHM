//https://www.acmicpc.net/problem/11576
#include <iostream>
#include <algorithm>

using namespace std;

// 앞자리부터 출력
void convert(int dcm, int base)
{
	if (dcm == 0)
	{
		return;
	}

	convert(dcm / base, base);
	cout << dcm % base << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, m;
	cin >> A >> B >> m;
	
	// abc(x) = a * x^2 + b * X^1 + c
	int dcm = 0;
	while (m--)
	{
		int sngl;
		cin >> sngl;

		dcm *= A;
		dcm += sngl;
	}
	
	convert(dcm, B);

	return 0;
}