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
		// 각 열의 T개수를 더해 전체 T개수 구하고 반환
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
			// 각 열을 뒤집은 경우, 뒤집지 않은 경우 중에서 더 작은 T값 더하기
			total += min(col_t_cnt, N - col_t_cnt);
		}

		return total;
	}

	// row행을 뒤집지 않은 경우
	int unfliped_t_cnt = flip(coins, row + 1);

	// row행을 뒤집은 경우
	coins[row] = ~coins[row];
	int fliped_t_cnt = flip(coins, row + 1);

	// 둘 중 더 작은 T 개수 반환
	return min(unfliped_t_cnt, fliped_t_cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// 입력 -> 비트마스크 벡터로 만들기
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

	// 동전 뒤집기 최소 T 개수 출력
	cout << flip(coins, 0);

	return 0;
}