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

// map ���� ������ �˻�
bool reachable(vector<vector<int>>& map, int x, int y)
{
	int N = map.size();
	return !(x < 0 || x >= N || y < 0 || y >= N);
}

// ���� ���� ������ �ʺ�켱 Ž������ üũ�ϸ� �����Ѵ�.
void bfs_island(vector<vector<int>>& map, vector<vector<info>>& cost_map, queue<pair<int, int>> &q, int island_idx)
{
	while (!q.empty())
	{
		int q_x = q.front().first;
		int q_y = q.front().second;
		q.pop();

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int n_x = q_x + dir_x[i];
			int n_y = q_y + dir_y[i];

			// ���� ������ map ���� ���̰�, ���� �� ������ �Է��ϱ� ���̸�
			if (reachable(map, n_x, n_y) && cost_map[n_x][n_y].island == 0)
			{
				// ���� ������ ���� ��
				if (map[n_x][n_y] == 1)
				{
					cost_map[n_x][n_y].island = island_idx;
					q.push({n_x, n_y});
				}
				/*
					���� ������ �ٴ��� �� 
					= ���� ������ ���� ��輱�̹Ƿ�, ���� ������ �Ÿ����� 0���� ���� 
				*/
				else
				{
					cost_map[q_x][q_y].cost = BOUNDARY;
				}
			}
		}
	}
}

// �����κ����� �Ÿ��� �ʺ�켱Ž������ �����ϸ� ���� �� ������ �ּҰŸ��� ���Ѵ�.
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

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int n_x = q_x + dir_x[i];
			int n_y = q_y + dir_y[i];

			// ���� ������ map�� ���� ���� �ְ�
			if (reachable(map, n_x, n_y))
			{
				// ���� ������ ���� �� ������ ������� �ʾҴٸ� 
				if (cost_map[n_x][n_y].island == 0)
				{
					cost_map[n_x][n_y].island = this_island;
					cost_map[n_x][n_y].cost = this_cost + 1;
					q.push({ n_x, n_y });
				}
				// ���� ������ �� ������ ���� ������ �ٸ� ���̶�� �Ÿ� �ּҰ� ����
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

	// �Է�
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

	// {�� �ѹ�, �����κ��� ������ �Ÿ�}�� ������ ����
	vector<vector<info>> cost_map(N, vector<info>(N, {0, -1}));
	queue<pair<int, int>> q;
	
	/*
		map ��ü�� ��ȸ�ϸ� �� ������ ������ �����Ѵ�.
		�̶� ���� �����ڸ��� �Ÿ����� 0 ���� ����
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

	// map ��ü�� ��ȸ�ϸ� ���� �����ڸ��� �ִ� ��ġ �ε����� ť�� push
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

	// �ʺ�켱 Ž������ ������ ���� ������ �Ÿ��� cost_map�� �����Ѵ�.
	// �ּҰ� ��ȯ
	cout << bfs_bridge(map, cost_map, q);

	return 0;
}