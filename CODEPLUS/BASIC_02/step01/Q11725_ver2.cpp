//https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int root = 1;

// �ʺ� �켱 Ž������ �� ����� �θ��� ã��
void bfs(vector<vector<int>>& tree, vector<int>& parent)
{
	parent[root] = -1;
	queue<int> q;
	q.push(root);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// ���� ����� �ڽĳ�� Ž��
		for (int child : tree[now])
		{
			// parent[�ڽĳ��]�� 0�̸� ���� ��� ���� �� ť�� push
			if (parent[child] == 0)
			{
				parent[child] = now;
				q.push(child);
			}
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


	// �ʺ� �켱 Ž������ �� ����� �θ��� ã��
	vector<int> parent(N + 1);
	bfs(tree, parent);


	// 2�� ������ �θ��� ���
	for (int i = 2; i < parent.size(); ++i)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}