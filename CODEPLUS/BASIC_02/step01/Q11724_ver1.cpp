//https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>

using  namespace std;

const int MAX = 1000;
bool check[MAX + 1];

int dfs(vector<vector<int>>& graph, int node)
{
	// ��尡 0�� �ƴ� �� : �ش� ����� �ڽĳ�� ��ŭ ��ȸ 
	int len = (node == 0) ? graph.size() - 1 : graph[node].size();
	int cnt = 0;

	for (int i = 0; i < len; ++i)
	{
		// ��尡 0�� �ƴ� �� : ���� üũ���� ���� �ڽ� ���� �̵�
		int next = (node == 0) ? i + 1 : graph[node][i];
		if (!check[next])
		{
			// ��尡 0�� ���� ���ǹ��� cnt�� --> �������� ����
			++cnt;
			check[next] = true;
			dfs(graph, next);
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	// ���� ����Ʈ�� �׷��� �����
	vector<vector<int>> graph(N + 1, vector<int>());
	for (int i = 0; i < M; ++i)
	{
		int first, second;
		cin >> first >> second;

		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	// ������ ���� ���
	cout << dfs(graph, 0);

	return 0;
}