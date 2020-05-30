//https://www.acmicpc.net/problem/2250
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct node {
	int parent, left, right;
};
struct level {
	int min, max;
};

int order = 1;
int max_depth;

// parent�� 0 �� ��Ʈ��� ã��
int find_root(vector<node>& tree)
{
	for (int i = 1; i < tree.size(); ++i)
	{
		if (tree[i].parent == 0)
		{
			return i;
		}
	}
	return 0;
}

// ������ȸ�� Ž���ϸ� ���� �� �ּ� �ε���, �ִ� �ε��� ã��
void dfs_inorder(vector<node> &tree, vector<level> &levels, int n, int depth)
{
	if (n == -1)
	{
		return;
	}

	dfs_inorder(tree, levels, tree[n].left, depth + 1);
	
	order++;
	levels[depth].min = min(levels[depth].min, order);
	levels[depth].max = max(levels[depth].max, order);
	max_depth = max(max_depth, depth);

	dfs_inorder(tree, levels, tree[n].right, depth + 1);
}

// �ʺ� �ִ��� ������ �� �ʺ� ���ϱ�
pair<int, int> get_max_level_n_width(vector<level> &levels)
{
	int max_level = 0, max_width = 0;

	for (int i = 1; i <= max_depth; ++i)
	{
		int width = levels[i].max - levels[i].min + 1;
		if (max_width < width)
		{
			max_width = width;
			max_level = i;
		}
	}
	return {max_level, max_width};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<node> tree(N + 1);
	for (int i = 0; i < N; ++i)
	{
		int p, l, r;
		cin >> p >> l >> r;
		
		// �ڽĳ�� ����
		tree[p].left = l;
		tree[p].right = r;
		
		// �θ��� ����
		if (l != -1)
		{
			tree[l].parent = p;
		}
		if (r != -1)
		{
			tree[r].parent = p;
		}
	}

	// ������ <�ּ� �ε���, �ִ� �ε���>�� ������ ���� 
	vector<level> levels(N + 1, { numeric_limits<int>::max() , 0 });


	// ������ȸ�� Ž���ϸ� ���� �� �ּ� �ε���, �ִ� �ε��� ã��
	dfs_inorder(tree, levels, find_root(tree), 1);
	

	// �ʺ� �ִ��� ������ �� �ʺ� ���ϱ�
	pair<int, int> max_p =  get_max_level_n_width(levels);
	cout << max_p.first << ' ' << max_p.second;

	return 0;
}