//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
using double_v = vector<vector<T>>;

struct pos {
	int x, y;
};

int N, M;
const int NEW_WALL = 3;
enum { LAND, WALL, VIRUS };
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
vector<pos> virus;
vector<pos> land;

// bfs로 새로 퍼진 바이러스 개수 구하기
int bfs(double_v<int> test_lab)
{
	// 큐에 바이러스 벡터의 위치값들 push
	queue<pos> q;
	for (int i = 0; i < virus.size(); ++i)
	{
		q.push(virus[i]);
	}

	int virus_cnt = 0;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dr_x[i];
			int ny = y + dr_y[i];

			// 범위를 벗어나면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			// 다음 위치가 빈 칸일 때, 바이러스 카운팅 후 큐에 push
			if (test_lab[nx][ny] == LAND)
			{
				++virus_cnt;
				test_lab[nx][ny] = VIRUS;
				q.push({ nx, ny });
			}
		}
	}
	return virus_cnt;
}

// dfs로 벽 3개 만들기
int dfs(double_v<int>& lab, int cnt, int strt)
{
	/*
		벽 3개가 새로 만들어지면
		해당 조건에서 새로 퍼진 바이러스 개수 리턴
	*/
	if (cnt == NEW_WALL)
	{
		return bfs(lab);
	}

	// land 벡터를 탐색하며 저장된 위치값으로 벽 만들기
	int min_virus = 987654321;
	for (int i = strt; i < land.size(); ++i)
	{
		lab[land[i].x][land[i].y] = WALL;

		// 다음 인덱스부터 탐색하는 dfs재귀함수 호출. 
		// 최소값 구하기
		min_virus = min(dfs(lab, cnt + 1, i + 1), min_virus);

		lab[land[i].x][land[i].y] = LAND;
	}
	return min_virus;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> M;
	double_v<int> lab(N, vector<int>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> lab[i][j];

			// 빈 칸일 때 : land벡터에 위치값 push
			if (lab[i][j] == LAND)
			{
				land.push_back({ i, j });
			}
			// 바이러스일 때 : virus벡터에 위치값 push
			else if (lab[i][j] == VIRUS)
			{
				virus.push_back({ i, j });
			}
		}
	}

	/*
		최대 안전 영역 출력
		안전영역 : 초기 빈칸 개수 - 새로 만든 벽 개수 - 퍼진 바이러스 개수

		--> 바이러스를 최소로 퍼지도록 하는 3개의 벽을 만들어야 함.
	*/
	cout << land.size() - NEW_WALL - dfs(lab, 0, 0);

	return 0;
}