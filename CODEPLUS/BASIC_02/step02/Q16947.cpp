//https://www.acmicpc.net/problem/16947
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 3000;
int info[MAX + 1];

enum flag { NOT_CYCLE = -2, CYCLE_NOT_FOUND = -1, VISITED = 1, CYCLE = 2 };

/*
	깊이 우선 탐색으로 싸이클 찾기
	반환값 < 0 : 싸이클을 아직 못찾았거나, 싸이클 바깥의 노드일 때
	반환값 > 0 : 싸이클을 찾았고, 반환값은 해당 시점의 탐색 노드
*/
int dfs(vector<vector<int>> &graph, int now, int before)
{
	// 전에 방문했던 노드일때 --> 해당 노드 반환
	if (info[now] == VISITED)
	{
		return now;
	}

	// 방문 체크
	info[now] = VISITED;

	// 해당 노드와 연결되어 있는 노드 탐색
	for (int next : graph[now])
	{
		// 이전 노드로 다시 되돌아가지 않음
		if (next == before)
		{
			continue;
		}

		/*
			다음 노드, 현재 노드를 인수로 dfs 재귀함수 호출. 
			다음 노드의 상태 반환값 돌려받음.
		*/
		int res = dfs(graph, next, now);

		// 반환값 > 0 : 싸이클을 찾았고, 반환값은 해당 시점의 탐색 노드
		if (res >= 0)
		{
			info[now] = CYCLE;
			
			// 반환된 노드가 현재 노드와 일치하면, 이 이전의 노드는 이제 싸이클 바깥의 노드임
			return (res == now) ? NOT_CYCLE : res;
		}
		/*
			반환값이 NOT_CYCLE일 때
			: 이미 싸이클을 찾았고 해당 노드는 싸이클 영역 바깥의 노드라는 뜻. 
			불필요하게 반복문을 모두 돌릴 이유가 없어졌으므로 빠르게 종료.
		*/
		else if (res == NOT_CYCLE)
		{
			return NOT_CYCLE;
		}
	}
	return CYCLE_NOT_FOUND;
}

// 너비 우선 탐색으로 싸이클과 연결되어 있는 노드들의 거리 계산
void bfs(vector<vector<int>>& graph, vector<int> &cost)
{
	queue<int> q;
	for (int i = 1; i < graph.size(); ++i)
	{
		// 싸이클이면 --> 큐에 push
		if (info[i] == CYCLE)
		{
			q.push(i);
		}
		// 싸이클이 아니면 --> cost값을 음수로 설정 
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
			// 싸이클이 아니고, 아직 방문하지 않은 노드일 때
			if (cost[next] < 0)
			{
				// 현재 노드의 cost값 + 1 하고 큐에 push
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

	// 입력
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

	// 깊이 우선 탐색으로 먼저 싸이클 찾기
	dfs(graph, 1, 0);

	// 너비 우선 탐색으로 각 노드들이 싸이클로부터 떨어진 거리 계산
	vector<int> cost(N + 1);
	bfs(graph, cost);

	// 출력
	for (int i = 1; i <= N; ++i)
	{
		cout << cost[i] << ' ';
	}

	return 0;
}