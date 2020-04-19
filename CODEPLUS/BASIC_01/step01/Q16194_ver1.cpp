//https://www.acmicpc.net/problem/16194
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> cost(n + 1);
	vector<int> min_cost(n + 1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		// ���� ���� ������ �ʾҴٴ� ��
		min_cost[i] = -1;
	}

	// ��ȭ�� : D[n] = min(D[n - i] + P[i])
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// �������� ī�尪�� 1 �� Pi �� 10,000 �̹Ƿ�, 
			// (min_cost == 0) ���θ� �������� �����ص� �������
			if (min_cost[i] < 0 || min_cost[i] > min_cost[i - j] + cost[j])
			{
				min_cost[i] = min_cost[i - j] + cost[j];
			}
		}
	}

	cout << min_cost[n];

	return 0;
}