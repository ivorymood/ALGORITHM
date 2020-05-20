//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20;
int min_dif = 1000;
int S[MAX][MAX];
int N;

// 점수 차이 구하기
int get_point_dif(vector<int>& team_s, vector<int>& team_l)
{
	int sum_s = 0;
	int sum_l = 0;
	for (int i = 0; i < team_s.size(); ++i)
	{
		for (int j = 0; j < team_s.size(); ++j)
		{
			sum_s += S[team_s[i]][team_s[j]];
			sum_l += S[team_l[i]][team_l[j]];
		}
	}
	return abs(sum_s - sum_l);
}

void dfs(vector<int> & team_s, vector<int> &team_l, int index)
{
	if (index == N)
	{
		// 각 팀이 모두 N / 2명이 아니면 X
		if (team_s.size() != N / 2 || team_l.size() != N / 2)
		{
			return;
		}

		// 최소 점수차이 구하기
		min_dif = min(min_dif, get_point_dif(team_s, team_l));

		return;
	}

	// index번째의 선수가 team_s에 속했을 때
	team_s.push_back(index);
	dfs(team_s, team_l, index + 1);
	team_s.pop_back();

	// index번째의 선수가 team_l에 속했을 때
	team_l.push_back(index);
	dfs(team_s, team_l, index + 1);
	team_l.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> S[i][j];
		}
	}

	// dfs - 백트랙킹으로 선수 조합해서 팀만들기
	vector<int> team_s, team_l;
	dfs(team_s, team_l, 0);

	cout << min_dif;

	return 0;
}