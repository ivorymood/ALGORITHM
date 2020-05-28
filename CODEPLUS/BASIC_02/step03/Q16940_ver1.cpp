//https://www.acmicpc.net/problem/16940
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// �Է����� �־��� BFS �湮������ �ùٸ��� �˻�
bool bfs(vector<vector<int>>& graph, queue<int>& test)
{
	// �������� ���� ���� 1�� �����ȴ�.
	if (test.front() != 1)
	{
		return false;
	}

	vector<bool> visit(graph.size());
	vector<int> parent(graph.size());
	queue<int> q;
	q.push(1);
	test.pop();


	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		visit[now] = true;

		// �ڽ� ��� �߿��� ���� �湮���� ���� ����� ������ ī����
		// parent���Ϳ� �θ� ��带 ����.
		int next_cnt = 0;
		for (int next : graph[now])
		{
			if (!visit[next])
			{
				++next_cnt;
				parent[next] = now;
			}
		}

		// ���� �湮���� ���� �ڽ� ��带 ��� ť�� ���� ������ �ݺ���
		while (next_cnt)
		{
			// �Է¼��� testť�� front�� �θ��尡 ���� ����̸�
			// bfsť�� push. testť pop
			int test_next = test.front();
			if (parent[test_next] == now)
			{
				q.push(test_next);
				test.pop();
				--next_cnt;
			}
			// �ƴϸ� false ��ȯ �� ����
			else
			{
				return false;
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

	// �־��� �Է� ������ ť�� �����.
	queue<int> test;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		test.push(num);
	}

	// �Է����� �־��� BFS �湮������ �ùٸ��� 1, �ƴϸ� 0 ���
	cout << bfs(graph, test);

	return 0;
}