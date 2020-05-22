//https://www.acmicpc.net/problem/13023
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2000;
const int FRIEND = 5;
bool check[MAX];

bool dfs(vector<vector<int>> &graph, int bf_idx, int depth, int k)
{
	// ����� k���� ��带 ��� ã���� true��ȯ
	if (depth == k)
	{
		return true;
	}

	/*
		��� ��尡 ù �������� ���ɼ��� ����ؾ� �Ѵ�.
		
		depth = 0 �� �� : for���� ��ü ��� ������ŭ ����.
		depth > 0 �� �� : for���� bf_idx ����� �ڽĳ�� ���� ��ŭ ����.
	*/
	int len = (depth == 0) ? graph.size() : graph[bf_idx].size();
	
	for (int i = 0; i < len; ++i)
	{
		// depth > 0 �� �� : bf_idx ����� �ڽĳ�带 �˻�
		int frnd = (depth == 0) ? i : graph[bf_idx][i];
		if (!check[frnd])
		{
			check[frnd] = true;
			// �ѹ��̶� depth�� k�� �����ϸ� true ��ȯ�ϰ� ����
			if (dfs(graph, frnd, depth + 1, k))
			{
				return true;
			}
			check[frnd] = false;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// dfs�� �׷��� Ž��
	cout << dfs(graph, -1, 0, FRIEND);

	return 0;
}