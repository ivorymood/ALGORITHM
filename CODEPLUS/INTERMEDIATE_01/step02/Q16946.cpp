//https://www.acmicpc.net/problem/16946
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct pos {
	int x, y;
};

int N, M;
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
const int MAX = 1000;
char map[MAX][MAX + 1];
int group[MAX][MAX];

int bfs(pos strt, int idx)
{
	// 큐에 시작지점 push 및 group에 idx값 저장
	queue<pos> q;
	q.push(strt);
	group[strt.x][strt.y] = idx;

	int cnt = 1;
	while (!q.empty())
	{
		pos p = q.front();
		q.pop();

		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int nx = p.x + dr_x[i];
			int ny = p.y + dr_y[i];

			// 범위를 넘어서면 continue
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			// 다음 영역이 빈칸이고 아직 group에 인덱스를 매기지 않았다면
			if (map[nx][ny] == '0' && group[nx][ny] == 0)
			{
				++cnt;
				group[nx][ny] = idx;
				q.push({ nx, ny });
			}
		}
	}
	// 해당 빈칸그룹의 영역크기 반환
	return cnt;
}

void plus_adj_group(vector<int>& cnts, pos p)
{
	set<int> s;
	// 4방향 탐색
	for (int k = 0; k < 4; ++k)
	{
		int nx = p.x + dr_x[k];
		int ny = p.y + dr_y[k];

		// 범위를 넘어서면 continue
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		{
			continue;
		}

		// 인접 영역이 빈칸이면 set에 그룹 인덱스 push (중복 방지)
		if (map[nx][ny] == '0')
		{
			s.insert(group[nx][ny]);
		}
	}

	// 인접한 빈칸그룹 인덱스의 영역크기 더하기
	int num = 1;
	for (int idx : s)
	{
		num += cnts[idx];
	}
	num %= 10;

	map[p.x][p.y] = num + '0';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> map[i];
	}

	/*
		Flood Fill
		cnts 배열에 각 빈칸 그룹의 연결된 영역 크기를 순서대로 저장
	*/
	vector<int> cnts(1);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// map[i][j]이 빈칸이고 group에 인덱스가 매겨지지 않았으면
			if (map[i][j] == '0' && group[i][j] == 0)
			{
				// bfs로 group배열에 인덱스를 저장 후, cnts배열에 영역크기 저장
				cnts.push_back(bfs({ i, j }, cnts.size()));
			}
		}
	}

	// map[i][j]이 벽이면, 인접한 빈칸그룹의 영역크기를 더한다
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == '1')
			{
				plus_adj_group(cnts, { i, j });
			}
		}
	}

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << map[i] << '\n';
	}

	return 0;
}