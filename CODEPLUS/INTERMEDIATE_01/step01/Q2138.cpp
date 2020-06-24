//https://www.acmicpc.net/problem/2138
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// idx - 1, idx, idx + 1의 전구 상태를 뒤집기
void flip(string& s, int idx)
{
	for (int i = idx - 1; i <= idx + 1; ++i)
	{
		if (i < 0 || i >= s.size())
		{
			continue;
		}

		if (s[i] == '0')
		{
			s[i] = '1';
		}
		else
		{
			s[i] = '0';
		}
	}
}

int get_flip_cnt(string from, const string& to, int N, bool flag)
{
	int cnt = 0;
	
	/*
		가장 처음의 위치에서 전구를 뒤집을지 말지에 따라서
		그 뒤의 전구 뒤집기가 결정되므로
		처음 위치에서 전구 뒤집는경우 / 안 뒤집는 경우 2번 판단해 주어야 함.
	*/
	if (flag)
	{
		flip(from, 0);
		++cnt;
	}

	// i - 1번째 전구상태를 기준으로 뒤집어나가기  (두번째 전구부터)
	for (int i = 1; i < N; ++i)
	{
		if (from[i - 1] != to[i - 1])
		{
			flip(from, i);
			++cnt;
		}
	}

	// 마지막 전구가 다르면 실패
	if (from[N - 1] != to[N - 1])
	{
		cnt = INF;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	string from, to;
	cin >> from >> to;

	// 처음 위치에서 전구 뒤집는경우 / 안 뒤집는 경우의 횟수를 각각 계산하여, 더 작은값 얻기
	int answer = min(get_flip_cnt(from, to, N, true), get_flip_cnt(from, to, N, false));
	
	cout << ((answer == INF) ? -1 : answer);

	return 0;
}