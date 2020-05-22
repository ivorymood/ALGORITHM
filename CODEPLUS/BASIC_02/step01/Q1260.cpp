//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 너비 우선 탐색
void bfs(vector<vector<int>>& list, vector<bool>& visited, int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int q_node = q.front();
		cout << q_node << ' ';
		
		q.pop();

		for (int i = 0; i < list[q_node].size(); ++i)
		{
			if (!visited[list[q_node][i]])
			{
				visited[list[q_node][i]] = true;
				q.push(list[q_node][i]);
			}
		}
	}

}

// 깊이 우선 탐색
void dfs(vector<vector<int>> &list, vector<bool> &visited, int start)
{
	cout << start << ' ';
	visited[start] = true;

	for (int i = 0; i < list[start].size(); ++i)
	{
		if (!visited[list[start][i]])
		{
			dfs(list, visited, list[start][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int node, edge, start;
	cin >> node >> edge >> start;

	// 인접 리스트 생성
	vector<vector<int>> list(node + 1);
	{
		int n1, n2;
		for (int i = 0; i < edge; ++i)
		{
			cin >> n1 >> n2;

			list[n1].push_back(n2);
			list[n2].push_back(n1);
		}
	}

	// 오름차순 정렬
	for (int i = 1; i <= node; ++i)
	{
		sort(list[i].begin(), list[i].end());
	}

	// dfs 출력
	vector<bool> visited(node + 1);
	dfs(list, visited, start);
	cout << '\n';

	// bfs 출력
	fill(visited.begin(), visited.end(), 0);
	bfs(list, visited, start);

	return 0;
}