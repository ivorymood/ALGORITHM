//https://www.acmicpc.net/problem/1939
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visit, int from, int dest, int weight)
{
	// �����ϸ� true��ȯ
	if (from == dest)
	{
		return true;
	}
	
	// ������ġ �湮 üũ
	visit[from] = true;
	
	// from�� ���� ��� Ž��
	for (auto& bridge : graph[from])
	{
		int to = bridge.first;
		int limit = bridge.second;

		// ���� �湮���� �ʾҰ�, ���� ���԰� �߷����� ���϶��
		if (!visit[to] && weight <= limit)
		{
			// �ѹ��̶� dest�� �����ߴٸ� true��ȯ
			if (dfs(graph, visit, to, dest, weight))
			{
				return true;
			}
		}
	}

	return false;
}

int binary_search(vector<vector<pair<int, int>>>& graph, int left, int right, int strt, int dest)
{
	int max_weight = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		// �߷��� mid �� ��, strt -> dest �̵��� �����ϸ� max_weight ����
		vector<bool> visit(graph.size());
		if (dfs(graph, visit, strt, dest, mid))
		{
			max_weight = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return max_weight;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int limit_min = numeric_limits<int>::max();
	int limit_max = 0;

	// �Է� �� �׷��� ����
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> graph(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int from, to, limit;
		cin >> from >> to >> limit;

		graph[from].push_back(make_pair(to, limit));
		graph[to].push_back(make_pair(from, limit));

		// ���� ������ �ּ�/�ִ밪 ���ϱ�
		limit_min = min(limit, limit_min);
		limit_max = max(limit, limit_max);
	}
	int strt, dest;
	cin >> strt >> dest;

	// strt���� dest�� �̵��� �� ������ �ִ빫�Ը� �̺�Ž������ ã��
	cout << binary_search(graph, limit_min, limit_max, strt, dest);

	return 0;
}