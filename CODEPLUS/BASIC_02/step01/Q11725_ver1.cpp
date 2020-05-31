//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>

using namespace std;

int root = 1;

void dfs(vector<vector<int>>& tree, vector<int>& parent, int now)
{
	// 현재 노드의 자식 노드 탐색
	for (int child : tree[now])
	{
		// 아직 방문하지 않은 parent[자식노드]에 현재노드 저장 후 dfs 재귀함수 호출
		if (parent[child] == 0)
		{
			parent[child] = now;
			dfs(tree, parent, child);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력받아 인접 리스트 만들기
	int N;
	cin >> N;
	vector<vector<int>> tree(N + 1, vector<int>());
	for (int i = 0; i < N - 1; ++i)
	{
		int first, second;
		cin >> first >> second;
		tree[first].push_back(second);
		tree[second].push_back(first);
	}


	// 깊이 우선 탐색으로 각 노드의 부모노드 찾기
	vector<int> parent(N + 1);
	parent[root] = -1;
	dfs(tree, parent, root);


	// 2번 노드부터 부모노드 출력
	for (int i = 2; i < parent.size(); ++i)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}