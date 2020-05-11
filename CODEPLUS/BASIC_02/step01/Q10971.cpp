//https://www.acmicpc.net/problem/10971
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10;
	int min_cost = 100'000'000;

	// �Է�
	int N;
	cin >> N;
	int W[MAX][MAX];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> W[i][j];
		}
	}

	// city �ε��� �迭
	// ù��° ���÷� �ٽ� ���ƿ��� ���ؼ� ũ�⸦ MAX + 1�� ����
	int city[MAX + 1] = { 0, };
	for (int i = 0; i < N; ++i)
	{
		city[i] = i;
	}

	// ��ȸ�� ������ ���, �ּ� ��ȸ��� ���ϱ� - ����Ž��
	do {
	
		bool possible = true;
		int cost = 0;
		
		// ���� ���������� �� ���� = ù��° ����
		city[N] = city[0];
		for (int i = 0; i < N; ++i)
		{
			// �� �� ���� ���� break
			if (W[city[i]][city[i + 1]] == 0)
			{
				possible = false;
				break;
			}

			cost += W[city[i]][city[i + 1]];
		}

		// ������ ��ȸ�� �ּҰ� ���ϱ�
		if (possible && min_cost > cost)
		{
			min_cost = cost;
		}
	
		/*
			��ȸ�� ȯ���̹Ƿ�, �������� 1�� �����ص� �ȴ�. 
			ex) A B C D == B C D A == C D A B == D A B C
		*/
	} while (next_permutation(city + 1, city + N));

	cout << min_cost;

	return 0;
}