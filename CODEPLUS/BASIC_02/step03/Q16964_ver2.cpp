//https://www.acmicpc.net/problem/16964
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];
int test_idx;
bool ok;

// 입력으로 주어진 DFS 방문순서가 올바른지 검사
void dfs(vector<vector<int>>& graph, vector<int>& test, int now)
{
	// 방문체크
	visited[now] = true;

	for (int i = 0; i < graph[now].size();)
	{
		int next = graph[now][i];
		
		// 아직 방문하지 않았고, 다음 입력노드와 일치하는 자식노드
		if (!visited[next] && next == test[test_idx + 1])
		{
			++test_idx;
			dfs(graph, test, next);
			
			// test벡터를 가리키는 인덱스가 끝에 도달했다면 성공. 종료
			if (test_idx >= test.size() - 1)
			{
				ok = true;
				return;
			}
			// dfs재귀함수 호출 후에는 다시 처음부터 반복문을 실행하여
			// 자식 노드 중에서 다음 입력노드를 찾는다.
			i = 0;
		}
		// 위 조건에 해당하지 않으면 인덱스값 증가
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
	vector<int> test(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> test[i];
	}

	// 입력으로 주어진 DFS 방문순서가 올바르면 1, 아니면 0 출력
	dfs(graph, test, 1);
	cout << ok;

	return 0;
}