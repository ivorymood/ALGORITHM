//https://www.acmicpc.net/problem/4963
#include <iostream>
#include <vector>

using namespace std;

int dir_x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dir_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int w, h;

// 깊이 우선 탐색
void dfs(vector<vector<int>> &map, int x, int y)
{
	// 방문한 위치는 0 저장
	map[x][y] = 0;

	// 대각선을 포함해서 8가지 방향 탐색
	for (int i = 0; i < 8; ++i)
	{
		int new_x = x + dir_x[i];
		int new_y = y + dir_y[i];

		// 이동 위치가 map 범위 안에 있고
		if (0 <= new_x && new_x < h && 0 <= new_y && new_y < w)
		{
			// 값이 1인 위치면(아직 방문하기 전) dfs 함수 재귀 호출
			if (map[new_x][new_y] > 0)
			{
				dfs(map, new_x, new_y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		// 입력
		cin >> w >> h;
		if (w == 0)
		{
			break;
		}
		vector<vector<int>> map(h, vector<int>(w));
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> map[i][j];
			}
		}

		// map 탐색
		int island = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				// 값이 1인 apt[i][j](아직 방문하기 전)에서 깊이우선 탐색
				if (map[i][j] > 0)
				{
					// 하나의 탐색영역이 시작되면 island + 1
					++island;
					dfs(map, i, j);
				}

			}
		}

		// 출력
		cout << island << '\n';
	}

	return 0;
}