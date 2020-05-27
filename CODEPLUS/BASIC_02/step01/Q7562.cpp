//https://www.acmicpc.net/problem/7562
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 너비 우선 탐색으로 목표지점까지의 최소거리 구하기
int bfs(int size, pair<int, int> strt, pair<int, int> fin)
{
	// 나이트가 이동가능한 8방향
	const int dir_x[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	const int dir_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	vector<vector<int>> map(size, vector<int>(size));
	queue<pair<int, int>> q;

	// 시작지점을 큐에 push
	q.push(strt);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 목표지점에 도착하면 map[x][y] = 이동횟수 반환
		if (x == fin.first && y == fin.second)
		{
			return map[x][y];
		}

		// 8방향 탐색
		for (int i = 0; i < 8; ++i)
		{
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];

			// 이동할 수 없는 위치일 때
			if (new_x < 0 || new_x >= size || new_y < 0 || new_y >= size)
			{
				continue;
			}

			// 아직 방문하지 않은 위치일 때 --> map에 이동횟수 저장, 큐에 push
			if (map[new_x][new_y] == 0)
			{
				map[new_x][new_y] = map[x][y] + 1;
				q.push({new_x, new_y});
			}
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		// 입력
		int size;
		pair<int, int> strt, fin;
		cin >> size;
		cin >> strt.first >> strt.second;
		cin >> fin.first >> fin.second;

		// 너비 우선 탐색으로 목표지점까지의 최소거리 구한 후 출력
		cout << bfs(size, strt, fin) << '\n';
	}

	return 0;
}