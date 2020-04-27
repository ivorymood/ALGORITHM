//https://www.acmicpc.net/problem/17404
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	const int MAX = 1000;
	int rgb[MAX + 1][3];
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	
	/*
	��ȭ��
		D[i] : i ��° ������ ��ĥ�� �ּ� ���.
		D[i] = i ��° �� ��ĥ ��� + (i - 1)��° ������ ��ĥ�� �ּ� ���

		i��° ���� (i - 1)��° ���� ���� ������ �ȵǹǷ�
		--> D[i][k] = rgb[i][k] + min(D[i - 1][(k + 1) % 3, D[i - 1][(k + 2) % d]]) (0 <= k <= 2)
	

		�߰�����) 1��° ���� N��° ���� ���� ������ �ȵȴ�.
		1��° ���� R�϶�, G�϶�, B�϶��� ���� ���ؼ� �ּҺ�� ���ϱ�
		
		* ���ǻ��� *
		a. 1��° ���� ������ X�϶�, D[1]�� D[2]�� �̹� ������ �ִ�
		b. 1��° ���� ������ X�϶�, N��° ���� ������ X�̸� �ȵȴ�.
	*/
	int min_cost = MAX * MAX;
	for (int k = 0; k < 3; k++)
	{
		int cost[MAX + 1][3] = { 0, };

		// ���ǻ��� a ó��
		for (int i = 0; i < 3; i++)
		{
			if (i == k)
			{
				cost[1][i] = rgb[1][i];
				continue;
			}
			cost[1][i] = 1000;
		}

		// ��ȭ�� ����
		for (int i = 2; i <= N; i++)
		{
			cost[i][0] = rgb[i][0] + min(cost[i - 1][1], cost[i - 1][2]);
			cost[i][1] = rgb[i][1] + min(cost[i - 1][0], cost[i - 1][2]);
			cost[i][2] = rgb[i][2] + min(cost[i - 1][0], cost[i - 1][1]);
		}

		// ���ǻ��� bó��
		for (int i = 0; i < 3; i++)
		{
			if (i == k)
			{
				continue;
			}
			min_cost = min(min_cost, cost[N][i]);
		}
	}

	cout << min_cost;

	return 0;
}