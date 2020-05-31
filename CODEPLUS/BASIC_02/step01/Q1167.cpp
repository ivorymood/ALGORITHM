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
	
	// �ִ밪�� �ִ밪 ���� ���� ��� ����
	if (max_cost < cost)
	{
		max_cost = cost;
		end_node = now;
	}

	// �ڽ� ��� Ž��
	for (node c : tree[now])
	{
		// �湮���� ���� �ڽĳ��� ����� ���ϰ� dfs ����Լ� ȣ��
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

	// �Է¹޾� ����ġ �ִ� ��������Ʈ �����
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
		���� ��忡������ ���̿켱Ž������ 
		�ִ� ���� ����� �ִ�� �ϴ� ���� ��� ���ϱ�
		(��𿡼����� �����ص� �ش� ���κ��� �ִ����� ����� ���� ��尡 ��������)
	*/
	vector<bool> visit(V + 1);
	dfs(tree, visit, 1, 0);
	
	/*
		ù��° Ž������ ���� ���� ������ ���̿켱Ž�� ����
		�ִ� ���� ����� �ִ�� �ϴ� ���� ��� ���ϱ�
	*/
	fill(visit.begin(), visit.end(), 0);
	dfs(tree, visit, end_node, 0);

	// ���
	cout << max_cost;

	return 0;
}