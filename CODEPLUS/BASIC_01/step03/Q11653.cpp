//https://www.acmicpc.net/problem/11653
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	// N�� ���μ� ã�� (��, N�� �Ҽ��� �ƴҶ�)
	for (int i = 2; i * i <= N; i++)
	{
		while (N % i == 0)
		{
			cout << i << '\n';
			N /= i;
		}
	}

	// ������ ���� �Ҽ� N ���
	if (N > 1)
	{
		cout << N;
	}

	return 0;
}