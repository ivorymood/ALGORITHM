//https://www.acmicpc.net/problem/1939
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visit, int from, int dest, int weight)
{
	// 도착하면 true반환
	if (from == dest)
	{
		return true;
	}
	
	// 현재위치 방문 체크
	visit[from] = true;
	
	// from의 인접 노드 탐색
	for (auto& bridge : graph[from])
	{
		int to = bridge.first;
		int limit = bridge.second;

		// 아직 방문하지 않았고, 현재 무게가 중량제한 이하라면
		if (!visit[to] && weight <= limit)
		{
			// 한번이라도 dest에 도달했다면 true반환
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

		// 중량이 mid 일 때, strt -> dest 이동이 가능하면 max_weight 갱신
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

	// 입력 및 그래프 생성
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> graph(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int from, to, limit;
		cin >> from >> to >> limit;

		graph[from].push_back(make_pair(to, limit));
		graph[to].push_back(make_pair(from, limit));

		// 무게 제한의 최소/최대값 구하기
		limit_min = min(limit, limit_min);
		limit_max = max(limit, limit_max);
	}
	int strt, dest;
	cin >> strt >> dest;

	// strt에서 dest로 이동할 때 가능한 최대무게를 이분탐색으로 찾기
	cout << binary_search(graph, limit_min, limit_max, strt, dest);

	return 0;
}