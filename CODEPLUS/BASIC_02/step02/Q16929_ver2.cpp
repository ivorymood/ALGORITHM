//https://www.acmicpc.net/problem/16929
#include <iostream>
#include <vector>

using namespace std;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };
int N, M;

/*
	최소 4개의 노드로 된 사이클이 만들어지기만 하면 된다.
	
	2차례 전의 노드와 다른 노드일 때만 방문할 수 있게 했을 때
	전에 방문했던 노드를 다시 방문하게 된다면 
	사이클이 가능한 경우이다. 
*/
bool dfs(vector<string>& map, vector<vector<bool>>& check, pair<int, int> now, pair<int, int> before)
{
	// 전에 방문한 위치일 때 true반환 및 종료
	if (check[now.first][now.second])
	{
		return true;
	}

	// 현재 위치 방문 체크
	check[now.first][now.second] = true;

	// 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		int new_x = now.first + dir_x[i];
		int new_y = now.second + dir_y[i];

		// 불가능한 위치일 때
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
		{
			continue;
		}

		// 색이 같을 때
		if (map[now.first][now.second] == map[new_x][new_y])
		{
			// 새 지점이 이전 지점과 다를 때
			if (!(new_x == before.first && new_y == before.second))
			{
				// 한번이라도 사이클이 가능하면 true반환 후 종료
				if (dfs(map, check, { new_x, new_y }, now))
				{
					return true;
				}
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

	// 방문여부를 체크할 bool 벡터
	vector<vector<bool>> check(N, vector<bool>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// 아직 방문하지 않았다면
			if (!check[i][j])
			{
				// dfs로 사이클이 만들어지는지 여부 검사
				if (dfs(map, check, { i, j }, { -1, -1 }))
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