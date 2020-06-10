//https://www.acmicpc.net/problem/16197
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr_x[4] = { 0, 1, 0, -1 }; 
int dr_y[4] = { 1, 0, -1, 0 };
int N, M, min_cnt = 11;
vector<vector<char>> map;

// 범위 밖에 있는지 체크
bool inline is_out(int x, int y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void go(pair<int, int> coin1, pair<int, int> coin2, int cnt)
{
	// 이동횟수가 최소값보다 커지면 종료
	if (cnt >= min_cnt)
	{
		return;
	}

	// 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		// 두 코인의 다음 위치
		int nc1_x = coin1.first + dr_x[i];
		int nc1_y = coin1.second + dr_y[i];
		int nc2_x = coin2.first + dr_x[i];
		int nc2_y = coin2.second + dr_y[i];

		// 범위 밖으로 나간 코인 개수 차감
		int left = 2;
		if (is_out(nc1_x, nc1_y))
		{
			--left;
		}
		if (is_out(nc2_x, nc2_y))
		{
			--left;
		}

		// 코인이 1개 남았다면 최소값 갱신 후 종료
		if (left == 1)
		{
			min_cnt = min(cnt + 1, min_cnt);
			return;
		}
		// 코인이 2개 남았다면
		else if (left == 2)
		{
			// 다음 칸이 벽일때 -> 원래 위치로 교체
			int move = 2;
			if (map[nc1_x][nc1_y] == '#')
			{
				nc1_x = coin1.first;
				nc1_y = coin1.second;
				--move;
			}
			if (map[nc2_x][nc2_y] == '#')
			{
				nc2_x = coin2.first;
				nc2_y = coin2.second;
				--move;
			}
			
			// 한 코인이라도 움직일 수 있으면 go 재귀함수 호출
			if (move > 0)
			{
				go({ nc1_x, nc1_y }, { nc2_x, nc2_y }, cnt + 1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> M;
	map = vector<vector<char>>(N, vector<char>(M));
	vector<pair<int, int>> coins;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];

			// 코인이면 벡터에 push
			if (map[i][j] == 'o')
			{
				coins.push_back({i, j});
			}
		}
	}

	// 두 코인의 초기값으로 go함수 호출
	go(coins[0], coins[1], 0);
	
	// 이동횟수가 10을 초과하면 -1 출력
	if (min_cnt > 10)
	{
		min_cnt = -1;
	}

	cout << min_cnt << '\n';

	return 0;
}