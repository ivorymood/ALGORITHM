//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>

using namespace std;

int root = 1;

void dfs(vector<vector<int>>& tree, vector<int>& parent, int now)
{
	// ���� ����� �ڽ� ��� Ž��
	for (int child : tree[now])
	{
		// ���� �湮���� ���� parent[�ڽĳ��]�� ������ ���� �� dfs ����Լ� ȣ��
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

	// �Է¹޾� ���� ����Ʈ �����
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


	// ���� �켱 Ž������ �� ����� �θ��� ã��
	vector<int> parent(N + 1);
	parent[root] = -1;
	dfs(tree, parent, root);


	// 2�� ������ �θ��� ���
	for (int i = 2; i < parent.size(); ++i)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}