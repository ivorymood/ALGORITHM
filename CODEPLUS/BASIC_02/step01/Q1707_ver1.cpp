//https://www.acmicpc.net/problem/1707
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graph)
{
	const int COLOR_A = 1;
	int len = graph.size();
	
	// check : �湮���θ� ǥ���� ���� 
	// color : �� ������ ǥ���� ����
	vector<bool> check(len);
	vector<int> color(len);
	queue<int> q;

	/*
		�׷����� �񿬰� �׷����� ���� �����Ƿ�
		��ü ��带 Ž���ϸ� ���� �湮���� ���� �׷����� ť�� push
	*/
	for (int i = 1; i < len; ++i)
	{
		if (!check[i])
		{
			color[i] = COLOR_A;
			q.push(i);

			while (!q.empty())
			{
				int node = q.front(); 
				q.pop();
				check[node] = true;

				// �ڽ� ��带 Ž���ؼ� ť�� push���θ� ����
				for (int j = 0; j < graph[node].size(); ++j)
				{
					int next = graph[node][j];
					
					// �ڽ� ����� ���� �̹� �ְ�, ���� ���� �ڽ� ����� ���� ������ --> false ��ȯ
					if (color[next] != 0 && color[node] == color[next])
					{
						return false;
					}
					// �ڽ� ����� ���� ������ --> ���� ���� �ٸ� ���� ������ ť�� push
					else if (color[next] == 0)
					{
						color[next] = color[node] * -1;
						q.push(next);
					}
				}
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> answer;

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

		// �̺б׷����� "YES", �ƴϸ� "NO" push
		answer.push_back(bfs(graph) ? "YES" : "NO");
	}

	for (string a : answer)
	{
		cout << a << '\n';
	}

	return 0;
}