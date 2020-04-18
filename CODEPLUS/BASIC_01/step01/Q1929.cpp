//https://www.acmicpc.net/problem/1929
#include <iostream>

using namespace std;

const int MAX = 1000000;
bool isno_prime[MAX + 1];

void check_prime()
{
	isno_prime[0] = true;
	isno_prime[1] = true;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (isno_prime[i] == false)
		{
			for (int j = 2; i * j <= MAX; j++)
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

	// �ִ밪 ������ �Ҽ�üũ �̸� �س���
	check_prime();

	// �Է�
	int M, N;
	cin >> M >> N;

	// ���
	for (int i = M; i <= N; ++i)
	{
		if (isno_prime[i] == false)
		{
			cout << i << '\n';
		}
	}

	return 0;
}