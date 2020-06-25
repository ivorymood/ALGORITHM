//https://www.acmicpc.net/problem/1285
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int flip(vector<unsigned int>& coins, int row)
{
	if (row == N)
	{
		// �� ���� T������ ���� ��ü T���� ���ϰ� ��ȯ
		int total = 0;
		for (int i = 0; i < N; ++i)
		{
			int col_t_cnt = 0;
			for (int j = 0; j < N; ++j)
			{
				if (coins[j] & (1 << i))
				{
					++col_t_cnt;
				}
			}
			// �� ���� ������ ���, ������ ���� ��� �߿��� �� ���� T�� ���ϱ�
			total += min(col_t_cnt, N - col_t_cnt);
		}

		return total;
	}

	// row���� ������ ���� ���
	int unfliped_t_cnt = flip(coins, row + 1);

	// row���� ������ ���
	coins[row] = ~coins[row];
	int fliped_t_cnt = flip(coins, row + 1);

	// �� �� �� ���� T ���� ��ȯ
	return min(unfliped_t_cnt, fliped_t_cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// �Է� -> ��Ʈ����ũ ���ͷ� �����
	cin >> N;
	vector<unsigned int> coins(N);
	for (int i = 0; i < N; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < N; ++j)
		{
			if (line[j] == 'T')
			{
				coins[i] |= (1 << j);
			}
		}
	}

	// ���� ������ �ּ� T ���� ���
	cout << flip(coins, 0);

	return 0;
}