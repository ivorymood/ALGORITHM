//https://www.acmicpc.net/problem/16940
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
	queue<int> q;
	q.push(1);
	test.pop();

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		visit[now] = true;

		// �ڽ� ��� �߿��� ���� �湮���� ���� ����� ������ ī����
		int next_cnt = graph[now].size();
		for (int next : graph[now])
		{
			if (visit[next])
			{
				--next_cnt;
			}
		}

		// ���� �湮���� ���� �ڽ� ��带 ��� ť�� ���� ������ �ݺ���
		while (next_cnt)
		{
			// �Է¼��� testť�� front�� ���� ����� �ڽ� ��� �߿��� ã�� �� ������ 
			// bfsť�� push. testť pop
			auto it_next = find(graph[now].begin(), graph[now].end(), test.front());
			if (it_next != graph[now].end())
			{
				q.push(*it_next);
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