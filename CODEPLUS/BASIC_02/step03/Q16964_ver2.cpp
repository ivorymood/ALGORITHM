//https://www.acmicpc.net/problem/16964
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];
int test_idx;
bool ok;

// �Է����� �־��� DFS �湮������ �ùٸ��� �˻�
void dfs(vector<vector<int>>& graph, vector<int>& test, int now)
{
	// �湮üũ
	visited[now] = true;

	for (int i = 0; i < graph[now].size();)
	{
		int next = graph[now][i];
		
		// ���� �湮���� �ʾҰ�, ���� �Է³��� ��ġ�ϴ� �ڽĳ��
		if (!visited[next] && next == test[test_idx + 1])
		{
			++test_idx;
			dfs(graph, test, next);
			
			// test���͸� ����Ű�� �ε����� ���� �����ߴٸ� ����. ����
			if (test_idx >= test.size() - 1)
			{
				ok = true;
				return;
			}
			// dfs����Լ� ȣ�� �Ŀ��� �ٽ� ó������ �ݺ����� �����Ͽ�
			// �ڽ� ��� �߿��� ���� �Է³�带 ã�´�.
			i = 0;
		}
		// �� ���ǿ� �ش����� ������ �ε����� ����
		else
		{
			++i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<vector<int>> graph(N + 1, vector<int>());
	for (int i = 0; i < N - 1; ++i)
	{
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}
	vector<int> test(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> test[i];
	}

	// �Է����� �־��� DFS �湮������ �ùٸ��� 1, �ƴϸ� 0 ���
	dfs(graph, test, 1);
	cout << ok;

	return 0;
}