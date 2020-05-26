//https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>

using  namespace std;

const int MAX = 1000;
bool check[MAX + 1];

void dfs(vector<vector<int>> &graph, int node)
{
	check[node] = true;

	// 해당 노드의 자식노드 만큼 순회 
	for (int i = 0; i < graph[node].size(); ++i)
	{
		int next = graph[node][i];
		if (!check[next])
		{
			dfs(graph, next);
		}
	}
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

	
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		// 아직 체크되지 않은 노드의 모든 자식노드들 순회 후 카운팅
		if (!check[i])
		{
			dfs(graph, i);
			++cnt;
		}
	}
	cout << cnt;

	return 0;
}