//https://www.acmicpc.net/problem/1981
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

const int MAX = 200;
int N;
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
int min_val = MAX;
int max_val = 0;

bool bfs(vector<vector<int>>& board, int mn, int mx)
{
	// [0][0]위치의 요소가 하한, 상한 요소값 범위 밖이면 false
	if (board[0][0] < mn || board[0][0] > mx)
	{
		return false;
	}

	queue<pos> q;
	q.push({ 0, 0 });
	vector<vector<bool>> visit(N, vector<bool>(N));
	visit[0][0] = true;

	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// 주어진 하한, 상한 요소값으로 [N - 1][N - 1]로 도달할 수 있으면 true
		if (p.x == N - 1 && p.y == N - 1)
		{
			return true;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			// 범위 밖이거나 방문한 적 있으면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny])
			{
				continue;
			}

			// 다음 위치의 요소가 하한, 상한 요소값 범위 밖이면 continue
			if (board[nx][ny] < mn || board[nx][ny] > mx)
			{
				continue;
			}

			visit[nx][ny] = true;
			q.push({ nx, ny });
		}

	}
	// [N - 1][N - 1]로 도달할 수 없으면 false
	return false;
}

bool check_gap_possible(vector<vector<int>>& board, int gap)
{
	/*
		요소값의 범위가 [최소요소, 최소요소 + gap]일 때,
		[0][0] ~ [N - 1][N - 1] 도달할 수 있는지 확인
	*/
	for (int i = min_val; i + gap <= max_val; ++i)
	{
		if (bfs(board, i, i + gap))
		{
			return true;
		}
	}
	return false;
}

// 갭(최대요소 - 최소요소)의 최소값을 이분탐색으로 찾기
int binary_search_gap(vector<vector<int>>& board)
{
	int left = 0;
	int right = max_val - min_val;
	int min_gap = right;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		// mid를 갭으로 했을 때, [0][0] ~ [N - 1][N - 1]까지 도달할 수 있는지 확인
		if (check_gap_possible(board, mid))
		{
			min_gap = min(mid, min_gap);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return min_gap;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];

			// 최소 요소, 최대 요소 구하기
			min_val = min(board[i][j], min_val);
			max_val = max(board[i][j], max_val);
		}
	}

	// 갭(최대요소 - 최소요소)의 최소값을 이분탐색으로 찾기
	cout << binary_search_gap(board);

	return 0;
}