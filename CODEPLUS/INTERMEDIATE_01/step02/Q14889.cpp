//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum {A, B};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<vector<int>> point(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> point[i][j];
		}
	}
	
	// mem������ �� ������ 0, �� ������ 1�� �ʱ�ȭ
	vector<int> mem(N, 1);
	for (int i = 0; i < N / 2; ++i)
	{
		mem[i] = 0;
	}

	// ������ ������� ���� �����ϴ� �پ��� ����� �� ���ؼ� �������� ���
	int min_dif = 987654321;
	do {
		vector<int> teamA, teamB;
		for (int i = 0; i < N; ++i)
		{
			// 0 -> team A, 1 -> team B
			if (mem[i] == A)
			{
				teamA.push_back(i);
			}
			else
			{
				teamB.push_back(i);
			}
		}
		
		int pA = 0, pB = 0;
		for (int i = 0; i < N / 2; ++i)
		{
			for (int j = 0; j < N / 2; ++j)
			{
				pA += point[teamA[i]][teamA[j]];
				pB += point[teamB[i]][teamB[j]];
			}
		}

		// �ּ����� ���ϱ�
		min_dif = min(min_dif, abs(pA - pB));
	
	} while (next_permutation(mem.begin(), mem.end()));

	cout << min_dif;

	return 0;
}