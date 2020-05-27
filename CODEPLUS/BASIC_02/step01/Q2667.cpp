//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 25;
bool check[N_MAX][N_MAX];
int dic_x[4] = { 0, 1, 0, -1 };
int dic_y[4] = { 1, 0, -1, 0 };

// 깊이 우선 탐색
void dfs(vector<vector<int>> &apt, vector<int> &cmplx, int x, int y)
{
	// 가장 마지막 cmplx 인덱스
	int now = cmplx.size() - 1;
	int N = apt.size();

	// 오른, 아래, 왼, 위 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dic_x[i];
		int newY = y + dic_y[i];

		// apt 인덱스의 범위 안에 있고
		if (0 <= newY && newY < N && 0 <= newX && newX < N)
		{
			// 아직 방문하기 전, 값이 1인 곳이면 dfs함수 재귀 호출
			if (!check[newX][newY] && apt[newX][newY] > 0)
			{
				// 가장 마지막 cmplx 인덱스의 값 + 1
				++cmplx[now];
				check[newX][newY] = true;
				dfs(apt, cmplx, newX, newY);
			}
		}
	}
}

int main()
{
	// 입력
	int N;
	scanf("%d", &N);
	vector<vector<int>> apt(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%1d", &apt[i][j]);
		}
	}

	// apt 탐색
	vector<int> cmplx;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 아직 방문하기 전, 값이 1인 apt[i][j]에서 깊이우선 탐색을 한다
			if (!check[i][j] && apt[i][j] > 0)
			{
				check[i][j] = true;
				cmplx.push_back(1);
				dfs(apt, cmplx, i, j);
			}
		}
	}

	// 오름차순 정렬
	sort(cmplx.begin(), cmplx.end());

	// 출력
	cout << cmplx.size() << '\n';
	for (int i : cmplx)
	{
		cout << i << '\n';
	}

	return 0;
}