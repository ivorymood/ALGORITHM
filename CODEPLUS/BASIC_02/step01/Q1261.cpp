//https://www.acmicpc.net/problem/1261
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &map)
{
	// x, y: ��ġ, cnt : ���� �μ� Ƚ��
	struct info {
		int x, y, cnt;
	};

	int dir_x[] = { 0, 1, 0, -1 };
	int dir_y[] = { 1, 0, -1, 0 };
	int N = map.size();
	int M = map[0].size();

	// �� �μ���/�� �μ��� ������ �����ϱ� ���� �� ���
	deque<info> dq;
	vector<vector<bool>> visit(N, vector<bool>(M));
	
	// ������ġ�� map[0][0]���� �־���. 
	dq.push_back({ 0, 0, 0 });
	--N; --M;
	
	while (!dq.empty())
	{
		info now = dq.front();
		dq.pop_front();

		// map[N][M]�� �����ϸ� �� �μ�Ƚ�� ��ȯ �� ���� 
		if (now.x == N && now.y == M)
		{
			return now.cnt;
		}

		// 4���� Ž��
		for (int i = 0; i < 4; ++i)
		{
			int nx = now.x + dir_x[i];
			int ny = now.y + dir_y[i];

			// ���� ���̰ų�, �̹� �湮������ ������ pass
			if (nx < 0 || nx > N || ny < 0 || ny > M || visit[nx][ny] == true)
			{
				continue;
			}

			visit[nx][ny] = true;

			// ���� ĭ�� ���� ��, �� �μ��� �ּ� Ƚ���� ���� push_back
			if (map[nx][ny] == 1)
			{
				dq.push_back({nx, ny, now.cnt + 1});
			}
			// ���� ĭ�� ����� ��, �켱������ �� ���� ������ push_front
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

	// �Է�
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

	// �ʺ�켱Ž������ �� �μ��� �ּ� Ƚ�� ���ϱ�
	cout << bfs(map);

	return 0;
}