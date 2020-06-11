//https://www.acmicpc.net/problem/1987
#include <iostream>
#include <vector>

using namespace std;

int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };

int go(vector<string>& alpha, vector<bool>& visit, int x, int y)
{
	int max_cnt = 1;

	// 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dr_x[i];
		int ny = y + dr_y[i];

		// 범위 밖을 벗어나면 continue
		if ((nx < 0 || nx >= alpha.size() || ny < 0 || ny >= alpha[0].size()))
		{
			continue;
		}

		// 다음칸의 알파벳을 방문한적이 없으면
		int idx = alpha[nx][ny] - 'A';
		if (!visit[idx])
		{
			visit[idx] = true;

			// 한번 이동할 때마다 이동횟수 + 1 
			int cnt = go(alpha, visit, nx, ny) + 1;

			// 최대값 구하기
			if (max_cnt < cnt)
			{
				max_cnt = cnt;
			}

			visit[idx] = false;
		}
	}
	return max_cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int R, C;
	cin >> R >> C;
	vector<string> alpha(R);
	for (int i = 0; i < R; ++i)
	{
		cin >> alpha[i];
	}

	// 알파벳 방문 체크할 bool벡터
	vector<bool> visit(26);
	// 첫번째 위치 방문 체크
	visit[alpha[0][0] - 'A'] = true;

	// 최대로 이동할 수 있는 칸수 출력
	cout << go(alpha, visit, 0, 0);

	return 0;
}
