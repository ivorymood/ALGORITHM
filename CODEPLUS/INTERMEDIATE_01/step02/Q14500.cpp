//https://www.acmicpc.net/problem/14500
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr_x[4] = {0, 1, 0, -1};
int dr_y[4] = {1, 0, -1, 0};
int N, M, max_sum;

// ㅗ를 제외한 나머지 도형 체크
void dfs(vector<vector<int>> &nums, vector<vector<bool>> &visit, int x, int y, int sum, int depth)
{
	// 4번째 칸 이동이 끝난 경우
	if (depth == 4)
	{
		max_sum = max(sum, max_sum);
		return;
	}
	// 이동이 불가능한 경우
	if (x < 0 || x >= N || y < 0 || y >= M)
	{
		return;
	}
	// 이미 지나온 칸인 경우
	if (visit[x][y])
	{
		return;
	}

	// 이동가능한 4방향 탐색 후 dfs재귀함수 호출
	visit[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		dfs(nums, visit, x + dr_x[i], y + dr_y[i], sum + nums[x][y], depth + 1);
	}
	visit[x][y] = false;
}

// ㅗ모양 도형 체크
void check_t_shape(vector<vector<int>>& nums, int x, int y)
{
	if (x + 2 < N)
	{
		int sum = nums[x][y] + nums[x + 1][y] + nums[x + 2][y];
		if (y - 1 >= 0)
		{
			max_sum = max(sum + nums[x + 1][y - 1], max_sum);
		}
		if (y + 1 < M)
		{
			max_sum = max(sum + nums[x + 1][y + 1], max_sum);
		}
	}

	if (y + 2 < M)
	{
		int sum = nums[x][y] + nums[x][y + 1] + nums[x][y + 2];
		if (x - 1 >= 0)
		{
			max_sum = max(sum + nums[x - 1][y + 1], max_sum);
		}
		if (x + 1 < N)
		{
			max_sum = max(sum + nums[x + 1][y + 1], max_sum);
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
	vector<vector<int>> nums(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> nums[i][j];
		}
	}

	// 입력받은 배열 탐색하며 테트로미노 합계 구하기
	vector<vector<bool>> visit(N, vector<bool>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			/*
				ㅗ를 제외한 나머지 도형
				: 해당 위치에서 이동가능한 방향으로 3칸이동하며 합계 구하고 max값 체크
			*/
			dfs(nums, visit, i, j, 0, 0);

			// ㅗ모양 도형 체크
			check_t_shape(nums, i, j);
		}
	}

	// 출력
	cout << max_sum;

	return 0;
}