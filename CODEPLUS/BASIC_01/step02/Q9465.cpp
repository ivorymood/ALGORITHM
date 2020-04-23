//https://www.acmicpc.net/problem/9465
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int stck[MAX + 1][2];
int max_p[MAX + 1][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		// ��ƼĿ �Է�
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> stck[j][i];
			}
		}

		/*
			D[i][j] = ���̰� i�� ��ƼĿ���� jĭ�� ����ϴ� ����� �ִ�����
			D[i][j] = max(D[i - 1][k]) + C[i][j]   (��, k�� 0 <= k <= 2 ���� j��°�� ����)
		
			- stck �迭�� 2ĭ�̱� ������ stck[i][0] : 1��° ��
		*/
		for (int i = 1; i <= n; i++)
		{
			max_p[i][0] = max(max_p[i - 1][1], max_p[i - 1][2]) + 0;
			max_p[i][1] = max(max_p[i - 1][0], max_p[i - 1][2]) + stck[i][0];
			max_p[i][2] = max(max_p[i - 1][0], max_p[i - 1][1]) + stck[i][1];
		}

		cout << max({ max_p[n][0], max_p[n][1], max_p[n][2] }) << '\n';
	}

	return 0;
}