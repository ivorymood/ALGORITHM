//https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>

using  namespace std;

const int MAX = 1000;
bool check[MAX + 1];

int dfs(vector<vector<int>>& graph, int node)
{
	// 노드가 0이 아닐 때 : 해당 노드의 자식노드 만큼 순회 
	int len = (node == 0) ? graph.size() - 1 : graph[node].size();
	int cnt = 0;

	for (int i = 0; i < len; ++i)
	{
		// 노드가 0이 아닐 때 : 아직 체크되지 않은 자식 노드로 이동
		int next = (node == 0) ? i + 1 : graph[node][i];
		if (!check[next])
		{
			// 노드가 0일 때만 유의미한 cnt값 --> 연결노드의 개수
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

	// 인접 리스트로 그래프 만들기
	vector<vector<int>> graph(N + 1, vector<int>());
	for (int i = 0; i < M; ++i)
	{
		int first, second;
		cin >> first >> second;

		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	// 연결요소 개수 출력
	cout << dfs(graph, 0);

	return 0;
}