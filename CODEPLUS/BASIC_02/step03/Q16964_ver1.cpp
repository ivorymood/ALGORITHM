//https://www.acmicpc.net/problem/16964
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];
int test_idx;

// �Է����� �־��� DFS �湮������ �ùٸ��� �˻�
bool dfs(vector<vector<int>>& graph, vector<int>& test, int now)
{
	// �湮 üũ
	visited[now] = true;

	// �Է¼������ ���ĵ� �� ����� ��������Ʈ�� ��ȸ
	// �Է¼����� ���� test������ �ε����� ���� �����Ѵ�.
	for (int next : graph[now])
	{
		if (!visited[next])
		{
			// ���� �ڽĳ��� ���� �Է³�尡 ��ġ���� ������ false��ȯ �� ����
			if (next != test[++test_idx])
			{
				return false;
			}
			// ��ġ�ϸ� dfs����Լ� ȣ�� ��� ��ȯ
			else
			{
				return dfs(graph, test, next);
			}
		}
	}

	return true;
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
	// order : �Է¼����� �־��� ������ �������� 
	vector<int> order(N + 1);
	vector<int> test(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> test[i];
		order[test[i]] = i;
	}

	// order�� ������� ��������Ʈ ����
	for (vector<int>& part : graph)
	{
		sort(part.begin(), part.end(), [&](const int& i, const int& j) {
			return order[i] < order[j];
			});
	}

	// �Է����� �־��� DFS �湮������ �ùٸ��� 1, �ƴϸ� 0 ���
	cout << dfs(graph, test, 1);

	return 0;
}