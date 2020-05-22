//https://www.acmicpc.net/problem/13023
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2000;
const int FRIEND = 5;
bool check[MAX];

bool dfs(vector<vector<int>> &graph, int bf_idx, int depth, int k)
{
	// 연결된 k개의 노드를 모두 찾으면 true반환
	if (depth == k)
	{
		return true;
	}

	/*
		모든 노드가 첫 시작점일 가능성을 고려해야 한다.
		
		depth = 0 일 때 : for문을 전체 노드 개수만큼 돌림.
		depth > 0 일 때 : for문을 bf_idx 노드의 자식노드 개수 만큼 돌림.
	*/
	int len = (depth == 0) ? graph.size() : graph[bf_idx].size();
	
	for (int i = 0; i < len; ++i)
	{
		// depth > 0 일 때 : bf_idx 노드의 자식노드를 검사
		int frnd = (depth == 0) ? i : graph[bf_idx][i];
		if (!check[frnd])
		{
			check[frnd] = true;
			// 한번이라도 depth가 k에 도달하면 true 반환하고 종료
			if (dfs(graph, frnd, depth + 1, k))
			{
				return true;
			}
			check[frnd] = false;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// dfs로 그래프 탐색
	cout << dfs(graph, -1, 0, FRIEND);

	return 0;
}