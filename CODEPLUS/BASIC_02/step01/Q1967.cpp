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

// postorder�� ���̿켱 Ž��
path dfs(vector<vector<node>> &tree, vector<bool> &visit, int now)
{
	visit[now] = true;

	// ������ ��ε��� ����ġ�� ������ ����
	vector<int> branch;
	
	// ��� dfs�Լ��� ������ ������� ���� �� �ִ밪�� ��� �ȴ�. 
	int cost_sum = 0;

	// ����� ��� Ž�� (Ž�� ����� �ڽ� ��尡 �ƴҼ� �ִ�)
	for (node c : tree[now])
	{
		if (!visit[c.to])
		{
			//  dfs����Լ� ȣ�� ��� : ������ ���
			path past = dfs(tree, visit, c.to);
			
			// (���� ��� ������ ����ġ�� + ���� ���~���� ��� ������ ����ġ) -> branch push
			branch.push_back(past.cost + c.weight);

			// �� ��� ��Ʋ� ���� �ִ밪 ����
			cost_sum = max(past.max_cost, cost_sum);
		}
	}

	// �������� ����
	sort(branch.begin(), branch.end(), [](const int &a, const int &b) ->bool{
		return a > b;
		});

	int cost = 0;
	
	// ���� ��忡 ����� ��尡 1�� �̻��̸�
	if (branch.size() >= 1)
	{
		// ���� ��� ���������� ����ġ ��
		cost = branch[0];
		cost_sum = max(cost, cost_sum);
	}

	/*
		���� ��忡 ����� ��尡 2�� �̻��̸�
		���� ���� ������ �߰��� ��ġ�� ��Ȳ.
		--> ���� = ���� ����Ʈ���� ����ġ�� + �ٸ� ���� ����Ʈ���� ����ġ��
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

	// �Է�
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

	// ���� ��忡������ postorder ���̿켱 Ž������ �ִ� ����(����ġ ��) ���ϱ�
	vector<bool> visit(N + 1);
	path p = dfs(tree, visit, 1);

	// ���
	cout << p.max_cost;

	return 0;
}