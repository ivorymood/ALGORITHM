//https://www.acmicpc.net/problem/1707
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graph)
{
	const int COLOR_A = 1;
	int len = graph.size();
	
	// check : 방문여부를 표시할 벡터 
	// color : 색 구분을 표시할 벡터
	vector<bool> check(len);
	vector<int> color(len);
	queue<int> q;

	/*
		그래프가 비연결 그래프일 수도 있으므로
		전체 노드를 탐색하며 아직 방문하지 않은 그래프를 큐에 push
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

				// 자식 노드를 탐색해서 큐에 push여부를 결정
				for (int j = 0; j < graph[node].size(); ++j)
				{
					int next = graph[node][j];
					
					// 자식 노드의 색이 이미 있고, 현재 노드와 자식 노드의 색이 같으면 --> false 반환
					if (color[next] != 0 && color[node] == color[next])
					{
						return false;
					}
					// 자식 노드의 색이 없으면 --> 현재 노드와 다른 색을 입히고 큐에 push
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

	// K : 테스트 케이스 개수
	int K;
	cin >> K;
	while (K--)
	{
		// V : 정점의 개수, E : 간선의 개수
		int V, E;
		cin >> V >> E;
		
		// 그래프 벡터 만들기
		vector<vector<int>> graph(V + 1, vector<int>());
		for (int i = 0; i < E; ++i)
		{
			int first, second;
			cin >> first >> second;
			graph[first].push_back(second);
			graph[second].push_back(first);
		}

		// 이분그래프면 "YES", 아니면 "NO" push
		answer.push_back(bfs(graph) ? "YES" : "NO");
	}

	for (string a : answer)
	{
		cout << a << '\n';
	}

	return 0;
}