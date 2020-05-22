//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두 팀의 점수 차이 구하기
int get_dif(vector<vector<int>> &S, int bitset)
{
	int team_s = 0;
	int team_l = 0;
	int len = S.size();

	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			// 비트가 1이면 team_s에 점수 합산
			if (bitset & ((1 << i) | (1 << j)))
			{
				team_s += S[i][j] + S[j][i];
			}
			// 비트가 0이면 team_l에 점수 합산
			if (~bitset & ((1 << i) | (1 << j)))
			{
				team_l += S[i][j] + S[j][i];
			}
		}
	}
	// 차이의 절대값 반환
	return abs(team_s - team_l);
}

// 1의 개수가 N / 2이면 true
bool check(int bitset, int N)
{
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (bitset & (1 << i))
		{
			++cnt;
		}
	}
	return cnt == N / 2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<vector<int>> S(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> S[i][j];
		}
	}

	// 비트마스크로 팀 조합 구하기
	int min_dif = 2000;
	for (int i = 1; i < (1 << N); ++i)
	{
		// 1의 개수가 N / 2이면 true
		if (check(i, N))
		{
			// 차이의 최소값 구하기
			min_dif = min(min_dif, get_dif(S, i));
		}
	}

	cout << min_dif;

	return 0;
}