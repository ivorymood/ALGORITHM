//https://www.acmicpc.net/problem/1932
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500;
int tri[MAX + 1][MAX + 1];
int D[MAX + 1][MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tri[i][j];
		}
	}

	/*
		��ȭ�� :
		D[i][j] = tri[i][j]�� �� �� �ִ� ����� i - 1��° �ִ밪 
				+ tri[i][j]
	*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + tri[i][j];
		}
	}

	// �ִ밪 ���
	int max = D[n][1];
	for (int i = 2; i <= n; i++)
	{
		max = (max < D[n][i]) ? D[n][i] : max;
	}
	cout << max;

	return 0;
}