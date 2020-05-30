//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
	int left, right;
};

// 전위 순회 출력
void dfs_preorder(vector<node> &tree, int n)
{
	if (n == -1)
	{
		return;
	}
	cout << static_cast<char>(n + 'A');
	dfs_preorder(tree, tree[n].left);
	dfs_preorder(tree, tree[n].right);
}

// 중위 순회 출력
void dfs_inorder(vector<node>& tree, int n)
{
	if (n == -1)
	{
		return;
	}
	dfs_inorder(tree, tree[n].left);
	cout << static_cast<char>(n + 'A');
	dfs_inorder(tree, tree[n].right);
}

// 후위 순회 출력
void dfs_postorder(vector<node>& tree, int n)
{
	if (n == -1)
	{
		return;
	}
	dfs_postorder(tree, tree[n].left);
	dfs_postorder(tree, tree[n].right);
	cout << static_cast<char>(n + 'A');
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<node> tree(N);
	for (int i = 0; i < N; ++i)
	{
		char rt, l, r;
		cin >> rt >> l >> r;

		rt -= 'A';
		tree[rt].left = ((l == '.') ? -1 : l - 'A');
		tree[rt].right = ((r == '.') ? -1 : r - 'A');
	}

	// 출력
	dfs_preorder(tree, 0);
	cout << '\n';
	dfs_inorder(tree, 0);
	cout << '\n';
	dfs_postorder(tree, 0);

	return 0;
}