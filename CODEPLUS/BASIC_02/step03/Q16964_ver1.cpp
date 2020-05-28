//https://www.acmicpc.net/problem/16964
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];
int test_idx;

// 입력으로 주어진 DFS 방문순서가 올바른지 검사
bool dfs(vector<vector<int>>& graph, vector<int>& test, int now)
{
	// 방문 체크
	visited[now] = true;

	// 입력순서대로 정렬된 각 노드의 인접리스트를 순회
	// 입력순서를 담은 test벡터의 인덱스는 점차 증가한다.
	for (int next : graph[now])
	{
		if (!visited[next])
		{
			// 다음 자식노드와 다음 입력노드가 일치하지 않으면 false반환 및 종료
			if (next != test[++test_idx])
			{
				return false;
			}
			// 일치하면 dfs재귀함수 호출 결과 반환
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

	// 입력
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
	// order : 입력순서로 주어진 노드들의 순서정보 
	vector<int> order(N + 1);
	vector<int> test(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> test[i];
		order[test[i]] = i;
	}

	// order의 순서대로 인접리스트 정렬
	for (vector<int>& part : graph)
	{
		sort(part.begin(), part.end(), [&](const int& i, const int& j) {
			return order[i] < order[j];
			});
	}

	// 입력으로 주어진 DFS 방문순서가 올바르면 1, 아니면 0 출력
	cout << dfs(graph, test, 1);

	return 0;
}