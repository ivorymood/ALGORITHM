//https://www.acmicpc.net/problem/14391
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N >> M;
	vector<vector<int>> P(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j)
		{
			P[i][j] = tmp[j] - '0';
		}
	}

	/*
		0 : ���ι���
		1 : ���ι���

		��Ʈ����ũ�� ���μ��� ����
	*/
	int max_sum = 0;
	for (int bitset = 0; bitset < (1 << N * M); ++bitset)
	{
		int sum = 0;

		// ���� ���� �� ���ϱ�
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (~bitset & (1 << (i * M + j)))
				{
					int num = 0;
					while (j < M && ~bitset & (1 << (i * M + j)))
					{
						num *= 10;
						num += P[i][j];
						++j;
					}
					sum += num;
				}
			}
		}

		// ���� ���� �� ���ϱ�
		for (int j = 0; j < M; ++j)
		{
			for (int i = 0; i < N; ++i)
			{
				if (bitset & (1 << (i * M + j)))
				{
					int num = 0;
					while (i < N && bitset & (1 << (i * M + j)))
					{
						num *= 10;
						num += P[i][j];
						++i;
					}
					sum += num;
				}
			}
		}

		// �ִ��� ���ϱ�
		max_sum = max(max_sum, sum);
	}

	cout << max_sum;

	return 0;
}