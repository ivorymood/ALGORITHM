//https://www.acmicpc.net/problem/16929
#include <iostream>
#include <vector>

using namespace std;

int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};
int N, M;

// 깊이 우선 탐색
bool dfs(vector<string> &map, vector<vector<int>> &check, int x, int y)
{
	// 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		// 불가능한 위치일 때
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
		{
			continue;
		}

		// 색이 같을 때
		if (map[x][y] == map[new_x][new_y])
		{
			// 아직 방문하지 않은 위치일 때, 
			// 이동횟수를 현재 이동횟수 + 1 저장 후 dfs 재귀호출
			if (check[new_x][new_y] == 0)
			{
				check[new_x][new_y] = check[x][y] + 1;
				// 한번이라도 사이클이 가능하면 true반환 후 종료
				if (dfs(map, check, new_x, new_y))
				{
					return true;
				}
			}
			// 이전에 방문했던 위치일 때, 현재 이동횟수와 적어도 3이상 차이나면 true반환
			else if (check[new_x][new_y] - check[x][y] >= 3)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	// 이동 횟수를 저장할 int 벡터
	vector<vector<int>> check(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// 아직 방문하지 않은 위치라면
			if (check[i][j] == 0)
			{
				// 방문횟수를 1로 저장 
				check[i][j] = 1;
				
				// dfs로 사이클이 만들어지는지 여부 검사
				if (dfs(map, check, i, j)) 
				{
					cout << "Yes";
					return 0;
				}
			}
		}
	}

	cout << "No";

	return 0;
}