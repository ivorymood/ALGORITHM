//https://www.acmicpc.net/problem/1261
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &map)
{
	// x, y: 위치, cnt : 벽을 부순 횟수
	struct info {
		int x, y, cnt;
	};

	int dir_x[] = { 0, 1, 0, -1 };
	int dir_y[] = { 1, 0, -1, 0 };
	int N = map.size();
	int M = map[0].size();

	// 벽 부수기/안 부수기 동작을 구분하기 위해 덱 사용
	deque<info> dq;
	vector<vector<bool>> visit(N, vector<bool>(M));
	
	// 시작위치는 map[0][0]으로 주어짐. 
	dq.push_back({ 0, 0, 0 });
	--N; --M;
	
	while (!dq.empty())
	{
		info now = dq.front();
		dq.pop_front();

		// map[N][M]에 도착하면 벽 부순횟수 반환 및 종료 
		if (now.x == N && now.y == M)
		{
			return now.cnt;
		}

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nx = now.x + dir_x[i];
			int ny = now.y + dir_y[i];

			// 범위 밖이거나, 이미 방문한적이 있으면 pass
			if (nx < 0 || nx > N || ny < 0 || ny > M || visit[nx][ny] == true)
			{
				continue;
			}

			visit[nx][ny] = true;

			// 다음 칸이 벽일 때, 벽 부수기 최소 횟수를 위해 push_back
			if (map[nx][ny] == 1)
			{
				dq.push_back({nx, ny, now.cnt + 1});
			}
			// 다음 칸이 빈방일 때, 우선순위가 더 높기 때문에 push_front
			else
			{
				dq.push_front({nx, ny, now.cnt});
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int M, N;
	cin >> M >> N;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; ++j)
		{
			map[i][j] = line[j] - '0';
		}
	}

	// 너비우선탐색으로 벽 부수기 최소 횟수 구하기
	cout << bfs(map);

	return 0;
}