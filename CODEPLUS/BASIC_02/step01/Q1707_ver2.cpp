//https://www.acmicpc.net/problem/1707
#include <iostream>
#include <vector>

using namespace std;

const int COLOR_A = 1;

bool dfs(vector<vector<int>>& graph, vector<int> &color, int node)
{
	// 현재 노드의 자식 노드를 탐색
	for (int i = 0; i < graph[node].size(); ++i)
	{
		int next = graph[node][i];
		
		// 자식 노드가 아직 방문 전일때, 현재노드의 반대 색을 입히고 dfs재귀함수 호출
		if (color[next] == 0)
		{
			color[next] = color[node] * -1;
			if (dfs(graph, color, next) == false)
			{
				return false;
			}
		}
		// 자식 노드의 색이 현재 노드색과 같을 때 false 반환
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

		/*
			그래프가 비연결 그래프일 수도 있으므로
			전체 노드를 탐색하며 아직 방문하지 않은 정점을 검사
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

		// 이분그래프면 "YES", 아니면 "NO" 출력
		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}