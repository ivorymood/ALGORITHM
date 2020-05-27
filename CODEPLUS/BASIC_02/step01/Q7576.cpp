//https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& box, queue<pair<int, int>>& q, int N, int M, int left)
{
	// 안익은 토마토가 없다면
	if (left == 0)
	{
		return 0;
	}

	int dir_x[4] = { 0, 1, 0, -1 };
	int dir_y[4] = { 1, 0, -1, 0 };
	int max_d = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		--left;

		// 모든 토마토가 익을 때까지 걸리는 일수 구하기
		max_d = (max_d < box[x][y]) ? box[x][y] : max_d;

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			// 닿을 수 없는 위치일 때
			if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
			{
				continue;
			}

			// 아직 익지 않은 토마토는 큐에 push하고 값을 현재 위치의 값 + 1
			if (box[new_x][new_y] == 0)
			{
				q.push({new_x, new_y});
				box[new_x][new_y] = box[x][y] + 1;
			}
		}
	}

	return (left > 0) ? -1 : max_d - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int M, N;
	cin >> M >> N;
	vector<vector<int>> box(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> box[i][j];
		}
	}

	queue<pair<int, int>> q;
	int left = M * N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// 익은 토마토는 큐에 push
			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
			// 토마토가 없으면 left - 1
			else if (box[i][j] == -1)
			{
				--left;
			}
		}
	}

	/*
		너비우선 탐색으로
		익히는게 가능한 토마토가 모두 익기까지의 최소 일수 구하기
	*/
	cout << bfs(box, q, N, M, left);

	return 0;
}