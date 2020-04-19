//https://www.acmicpc.net/problem/10844
#include <iostream>

using namespace std;

const int DIV = 1000000000;
const int MAX = 100;
int sum[MAX + 1][10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	// ��ȭ�� : D[N][i] = D[N - 1][i - 1] + D[N - 1][i + 1]
	for (int i = 1; i < 10; i++)
	{
		sum[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j < 9)
			{
				sum[i][j] += sum[i - 1][j + 1];
			}
			if (j > 0)
			{
				sum[i][j] += sum[i - 1][j - 1];
			}
			sum[i][j] %= DIV;
		}
	}

	// sum[n][i]�� ���ϴ� �������� �����÷ΰ� �߻��� �� �ֱ� ������
	// long long �ڷ������� ����
	long long answer = 0;
	for (int i = 0; i < 10; i++)
	{
		answer += sum[n][i];
	}
	cout << answer % DIV;

	return 0;
}