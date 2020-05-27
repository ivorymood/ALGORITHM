//https://www.acmicpc.net/problem/1707
#include <iostream>
#include <vector>

using namespace std;

const int COLOR_A = 1;

bool dfs(vector<vector<int>>& graph, vector<int> &color, int node)
{
	// ���� ����� �ڽ� ��带 Ž��
	for (int i = 0; i < graph[node].size(); ++i)
	{
		int next = graph[node][i];
		
		// �ڽ� ��尡 ���� �湮 ���϶�, �������� �ݴ� ���� ������ dfs����Լ� ȣ��
		if (color[next] == 0)
		{
			color[next] = color[node] * -1;
			if (dfs(graph, color, next) == false)
			{
				return false;
			}
		}
		// �ڽ� ����� ���� ���� ������ ���� �� false ��ȯ
		else if (color[next] == color[node])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// K : �׽�Ʈ ���̽� ����
	int K;
	cin >> K;
	while (K--)
	{
		// V : ������ ����, E : ������ ����
		int V, E;
		cin >> V >> E;

		// �׷��� ���� �����
		vector<vector<int>> graph(V + 1, vector<int>());
		for (int i = 0; i < E; ++i)
		{
			int first, second;
			cin >> first >> second;
			graph[first].push_back(second);
			graph[second].push_back(first);
		}

		/*
			�׷����� �񿬰� �׷����� ���� �����Ƿ�
			��ü ��带 Ž���ϸ� ���� �湮���� ���� ������ �˻�
		*/
		vector<int> color(V + 1);
		bool flag = true;
		for (int i = 1; i < graph.size(); ++i)
		{
			if (color[i] == 0)
			{
				color[i] = COLOR_A;
				if (dfs(graph, color, i) == false)
				{
					flag = false;
				}
			}
		}

		// �̺б׷����� "YES", �ƴϸ� "NO" ���
		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}