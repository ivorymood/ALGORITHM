//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// �ʺ� �켱 Ž��
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

// ���� �켱 Ž��
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

	// �Է�
	int node, edge, start;
	cin >> node >> edge >> start;

	// ���� ����Ʈ ����
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

	// �������� ����
	for (int i = 1; i <= node; ++i)
	{
		sort(list[i].begin(), list[i].end());
	}

	// dfs ���
	vector<bool> visited(node + 1);
	dfs(list, visited, start);
	cout << '\n';

	// bfs ���
	fill(visited.begin(), visited.end(), 0);
	bfs(list, visited, start);

	return 0;
}