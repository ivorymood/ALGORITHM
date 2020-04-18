//https://www.acmicpc.net/problem/1978
#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	}

	// �������� �־����� ���� 1000���� �̹Ƿ� i * i�� �ص� �����÷ο�X
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, cnt = 0;
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;

		if (isPrime(num))
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}