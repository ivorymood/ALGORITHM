//https://www.acmicpc.net/problem/16947
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 3000;
int info[MAX + 1];

enum flag { NOT_CYCLE = -2, CYCLE_NOT_FOUND = -1, VISITED = 1, CYCLE = 2 };

/*
	���� �켱 Ž������ ����Ŭ ã��
	��ȯ�� < 0 : ����Ŭ�� ���� ��ã�Ұų�, ����Ŭ �ٱ��� ����� ��
	��ȯ�� > 0 : ����Ŭ�� ã�Ұ�, ��ȯ���� �ش� ������ Ž�� ���
*/
int dfs(vector<vector<int>> &graph, int now, int before)
{
	// ���� �湮�ߴ� ����϶� --> �ش� ��� ��ȯ
	if (info[now] == VISITED)
	{
		return now;
	}

	// �湮 üũ
	info[now] = VISITED;

	// �ش� ���� ����Ǿ� �ִ� ��� Ž��
	for (int next : graph[now])
	{
		// ���� ���� �ٽ� �ǵ��ư��� ����
		if (next == before)
		{
			continue;
		}

		/*
			���� ���, ���� ��带 �μ��� dfs ����Լ� ȣ��. 
			���� ����� ���� ��ȯ�� ��������.
		*/
		int res = dfs(graph, next, now);

		// ��ȯ�� > 0 : ����Ŭ�� ã�Ұ�, ��ȯ���� �ش� ������ Ž�� ���
		if (res >= 0)
		{
			info[now] = CYCLE;
			
			// ��ȯ�� ��尡 ���� ���� ��ġ�ϸ�, �� ������ ���� ���� ����Ŭ �ٱ��� �����
			return (res == now) ? NOT_CYCLE : res;
		}
		/*
			��ȯ���� NOT_CYCLE�� ��
			: �̹� ����Ŭ�� ã�Ұ� �ش� ���� ����Ŭ ���� �ٱ��� ����� ��. 
			���ʿ��ϰ� �ݺ����� ��� ���� ������ ���������Ƿ� ������ ����.
		*/
		else if (res == NOT_CYCLE)
		{
			return NOT_CYCLE;
		}
	}
	return CYCLE_NOT_FOUND;
}

// �ʺ� �켱 Ž������ ����Ŭ�� ����Ǿ� �ִ� ������ �Ÿ� ���
void bfs(vector<vector<int>>& graph, vector<int> &cost)
{
	queue<int> q;
	for (int i = 1; i < graph.size(); ++i)
	{
		// ����Ŭ�̸� --> ť�� push
		if (info[i] == CYCLE)
		{
			q.push(i);
		}
		// ����Ŭ�� �ƴϸ� --> cost���� ������ ���� 
		else
		{
			cost[i] = -1;
		}
	}
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : graph[now])
		{
			// ����Ŭ�� �ƴϰ�, ���� �湮���� ���� ����� ��
			if (cost[next] < 0)
			{
				// ���� ����� cost�� + 1 �ϰ� ť�� push
				cost[next] = cost[now] + 1;
				q.push(next);
			}
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
	for (int i = 0; i < N; ++i)
	{
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	// ���� �켱 Ž������ ���� ����Ŭ ã��
	dfs(graph, 1, 0);

	// �ʺ� �켱 Ž������ �� ������ ����Ŭ�κ��� ������ �Ÿ� ���
	vector<int> cost(N + 1);
	bfs(graph, cost);

	// ���
	for (int i = 1; i <= N; ++i)
	{
		cout << cost[i] << ' ';
	}

	return 0;
}