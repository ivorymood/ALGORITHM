//https://www.acmicpc.net/problem/6588
#include <iostream>

using namespace std;

const int MAX = 1000000;
bool isno_prime[MAX + 1];

void check_prime()
{
	for (int i = 2; i * i <= MAX; ++i)
	{
		if (isno_prime[i] == false)
		{
			for (int j = 2; i * j <= MAX; ++j)
			{
				isno_prime[i * j] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �����佺�׳׽��� ü : �̸� MAX������ �Ҽ����� �س���
	check_prime();

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}

		bool possible = false;
		for (int i = 3; i < n; i += 2)
		{
			// �Ѵ� �Ҽ��̸� ���
			if (!isno_prime[i] && !isno_prime[n - i])
			{
				cout << n << " = " << i << " + " << (n - i) << '\n';
				possible = true;
				break;
			}
		}

		if (!possible)
		{
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}

	return 0;
}