//https://www.acmicpc.net/problem/2156
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10000;
int liq[MAX + 1];
int M[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> liq[i];
	}
	/*
	��ȭ��
		M[i] : i��° ���� ���� �ִ��� ������ ��

		M[i] : max(0������, 1������, 2������)

		0������: i��° ������ ����. 
		1������: i - 1��° ������ ����. i��° ����.
		2������: i - 2��° ������ ����. i - 1��°, i��° ����.
	*/
	M[1] = liq[1];
	M[2] = M[1] + liq[2];
	for (int i = 3; i <= n; i++)
	{
		M[i] = max({M[i - 1]
				, M[i - 2] + liq[i]
				, M[i - 3] + liq[i - 1] + liq[i]});
	}

	cout << M[n];

	return 0;
}