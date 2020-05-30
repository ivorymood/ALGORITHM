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

// parent가 0 인 루트노드 찾기
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

// 중위순회로 탐색하며 레벨 별 최소 인덱스, 최대 인덱스 찾기
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

// 너비가 최대인 레벨과 그 너비값 구하기
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

	// 입력
	int N;
	cin >> N;
	vector<node> tree(N + 1);
	for (int i = 0; i < N; ++i)
	{
		int p, l, r;
		cin >> p >> l >> r;
		
		// 자식노드 저장
		tree[p].left = l;
		tree[p].right = r;
		
		// 부모노드 저장
		if (l != -1)
		{
			tree[l].parent = p;
		}
		if (r != -1)
		{
			tree[r].parent = p;
		}
	}

	// 레벨별 <최소 인덱스, 최대 인덱스>를 저장할 벡터 
	vector<level> levels(N + 1, { numeric_limits<int>::max() , 0 });


	// 중위순회로 탐색하며 레벨 별 최소 인덱스, 최대 인덱스 찾기
	dfs_inorder(tree, levels, find_root(tree), 1);
	

	// 너비가 최대인 레벨과 그 너비값 구하기
	pair<int, int> max_p =  get_max_level_n_width(levels);
	cout << max_p.first << ' ' << max_p.second;

	return 0;
}