//https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>

using namespace std;

struct node {
	int to, weight;
};

int max_cost;
int end_node;

void dfs(vector<vector<node>> &tree, vector<bool> &visit, int now, int cost)
{
	visit[now] = true;
	
	// 최대값과 최대값 시점 말단 노드 갱신
	if (max_cost < cost)
	{
		max_cost = cost;
		end_node = now;
	}

	// 자식 노드 탐색
	for (node c : tree[now])
	{
		// 방문하지 않은 자식노드면 비용을 더하고 dfs 재귀함수 호출
		if (!visit[c.to])
		{
			dfs(tree, visit, c.to, cost + c.weight);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력받아 가중치 있는 인접리스트 만들기
	int V;
	cin >> V;
	vector<vector<node>> tree(V + 1, vector<node>());
	for (int i = 1; i <= V; ++i)
	{
		int from, to, weight;
		cin >> from;
		while (true)
		{
			cin >> to;
			if (to == -1)
			{
				break;
			}
			cin >> weight;

			tree[from].push_back({ to, weight});
		}
	}

	/*
		임의 노드에서부터 깊이우선탐색으로 
		최대 비용과 비용을 최대로 하는 말단 노드 구하기
		(어디에서부터 시작해도 해당 노드로부터 최대비용을 만드는 말단 노드가 구해진다)
	*/
	vector<bool> visit(V + 1);
	dfs(tree, visit, 1, 0);
	
	/*
		첫번째 탐색에서 구한 말단 노드부터 깊이우선탐색 시작
		최대 비용과 비용을 최대로 하는 말단 노드 구하기
	*/
	fill(visit.begin(), visit.end(), 0);
	dfs(tree, visit, end_node, 0);

	// 출력
	cout << max_cost;

	return 0;
}