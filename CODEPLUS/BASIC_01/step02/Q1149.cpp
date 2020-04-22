//https://www.acmicpc.net/problem/1149
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 1000;
	int min_cost[MAX + 1][3];

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int pR, pG, pB;
		cin >> pR >> pG >> pB;
		
		// n��° ���� R�� ��� : n - 1��° ���� G or B
		// �� �� �� ���� ��뿡 n��° ��ĥ ����� ���ϱ�
		min_cost[i][0] = min(min_cost[i - 1][1], min_cost[i - 1][2]) + pR;
		min_cost[i][1] = min(min_cost[i - 1][0], min_cost[i - 1][2]) + pG;
		min_cost[i][2] = min(min_cost[i - 1][0], min_cost[i - 1][1]) + pB;
	}

	// �ּҰ� ���
	cout << min({ min_cost[T][0], min_cost[T][1], min_cost[T][2] });

	return 0;
}