//https://www.acmicpc.net/problem/1967
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int to, weight;
};
struct path {
	int cost, max_cost;
};

// postorder로 깊이우선 탐색
path dfs(vector<vector<node>> &tree, vector<bool> &visit, int now)
{
	visit[now] = true;

	// 지나온 경로들의 가중치를 저장할 벡터
	vector<int> branch;
	
	// 모든 dfs함수를 지나며 얻어지는 지름 중 최대값을 담게 된다. 
	int cost_sum = 0;

	// 연결된 노드 탐색 (탐색 대상이 자식 노드가 아닐수 있다)
	for (node c : tree[now])
	{
		if (!visit[c.to])
		{
			//  dfs재귀함수 호출 결과 : 지나온 경로
			path past = dfs(tree, visit, c.to);
			
			// (이전 노드 시점의 가중치합 + 현재 노드~이전 노드 사이의 가중치) -> branch push
			branch.push_back(past.cost + c.weight);

			// 전 경로 통틀어서 지름 최대값 갱신
			cost_sum = max(past.max_cost, cost_sum);
		}
	}

	// 내림차순 정렬
	sort(branch.begin(), branch.end(), [](const int &a, const int &b) ->bool{
		return a > b;
		});

	int cost = 0;
	
	// 현재 노드에 연결된 노드가 1개 이상이면
	if (branch.size() >= 1)
	{
		// 현재 노드 시점에서의 가중치 합
		cost = branch[0];
		cost_sum = max(cost, cost_sum);
	}

	/*
		현재 노드에 연결된 노드가 2개 이상이면
		현재 노드는 지름의 중간에 위치한 상황.
		--> 지름 = 한쪽 서브트리의 가중치합 + 다른 한쪽 서브트리의 가중치합
	*/ 
	if (branch.size() >= 2)
	{
		cost_sum = max(branch[0] + branch[1], cost_sum);
	}

	return {cost, cost_sum};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<vector<node>> tree(N + 1, vector<node>());
	for (int i = 0; i < N - 1; ++i)
	{
		int from, to, weight;
		cin >> from >> to >> weight;

		tree[from].push_back({ to, weight});
		tree[to].push_back({ from, weight});
	}

	// 임의 노드에서부터 postorder 깊이우선 탐색으로 최대 지름(가중치 합) 구하기
	vector<bool> visit(N + 1);
	path p = dfs(tree, visit, 1);

	// 출력
	cout << p.max_cost;

	return 0;
}