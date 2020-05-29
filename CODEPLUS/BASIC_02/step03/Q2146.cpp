//https://www.acmicpc.net/problem/2146
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };
enum {BOUNDARY = 0, MAX = 100};

struct info {
	int island, cost;
};

// map 범위 내인지 검사
bool reachable(vector<vector<int>>& map, int x, int y)
{
	int N = map.size();
	return !(x < 0 || x >= N || y < 0 || y >= N);
}

// 섬에 대한 정보를 너비우선 탐색으로 체크하며 저장한다.
void bfs_island(vector<vector<int>>& map, vector<vector<info>>& cost_map, queue<pair<int, int>> &q, int island_idx)
{
	while (!q.empty())
	{
		int q_x = q.front().first;
		int q_y = q.front().second;
		q.pop();

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int n_x = q_x + dir_x[i];
			int n_y = q_y + dir_y[i];

			// 다음 지점이 map 범위 내이고, 아직 섬 정보를 입력하기 전이면
			if (reachable(map, n_x, n_y) && cost_map[n_x][n_y].island == 0)
			{
				// 다음 지점이 섬일 때
				if (map[n_x][n_y] == 1)
				{
					cost_map[n_x][n_y].island = island_idx;
					q.push({n_x, n_y});
				}
				/*
					다음 지점이 바다일 때 
					= 현재 지점은 섬의 경계선이므로, 현재 지점의 거리값을 0으로 저장 
				*/
				else
				{
					cost_map[q_x][q_y].cost = BOUNDARY;
				}
			}
		}
	}
}

// 섬으로부터의 거리를 너비우선탐색으로 저장하며 섬과 섬 사이의 최소거리를 구한다.
int bfs_bridge(vector<vector<int>>& map,vector<vector<info>> &cost_map, queue<pair<int, int>> &q)
{
	int min_cost = MAX * MAX;

	while (!q.empty())
	{
		int q_x = q.front().first;
		int q_y = q.front().second;
		int this_island = cost_map[q_x][q_y].island;
		int this_cost = cost_map[q_x][q_y].cost;
		q.pop();

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int n_x = q_x + dir_x[i];
			int n_y = q_y + dir_y[i];

			// 다음 지점이 map의 범위 내에 있고
			if (reachable(map, n_x, n_y))
			{
				// 다음 지점에 아직 섬 정보가 저장되지 않았다면 
				if (cost_map[n_x][n_y].island == 0)
				{
					cost_map[n_x][n_y].island = this_island;
					cost_map[n_x][n_y].cost = this_cost + 1;
					q.push({ n_x, n_y });
				}
				// 다음 지점의 섬 정보가 현재 지점과 다른 섬이라면 거리 최소값 갱신
				else if (cost_map[n_x][n_y].island != this_island)
				{
					min_cost = min(this_cost + cost_map[n_x][n_y].cost, min_cost);
				}
			}
		}
	}
	return min_cost;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
		}
	}

	// {섬 넘버, 섬으로부터 떨어진 거리}를 저장할 벡터
	vector<vector<info>> cost_map(N, vector<info>(N, {0, -1}));
	queue<pair<int, int>> q;
	
	/*
		map 전체를 순회하며 섬 영역에 정보를 저장한다.
		이때 섬의 가장자리의 거리값은 0 으로 저장
	*/
	int island_cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1 && cost_map[i][j].island == 0)
			{
				++island_cnt;
				cost_map[i][j].island = island_cnt;
				q.push({i, j});
				bfs_island(map, cost_map, q, island_cnt);
			}
		}
	}

	// map 전체를 순회하며 섬의 가장자리에 있는 위치 인덱스를 큐에 push
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (cost_map[i][j].cost == BOUNDARY)
			{
				q.push({ i, j });
			}
		}
	}

	// 너비우선 탐색으로 섬으로 부터 떨어진 거리를 cost_map에 저장한다.
	// 최소값 반환
	cout << bfs_bridge(map, cost_map, q);

	return 0;
}