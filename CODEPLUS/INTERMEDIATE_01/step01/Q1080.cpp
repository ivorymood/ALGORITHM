//https://www.acmicpc.net/problem/1080
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<string> &v, int x, int y)
{
	for (int i = x; i < x + 3; ++i)
	{
		for (int j = y; j < y + 3; ++j)
		{
			if (v[i][j] == '0')
			{
				v[i][j] = '1';
			}
			else
			{
				v[i][j] = '0';
			}
		}
	}
}

bool check(vector<string> &from, vector<string> &to)
{
	int N = from.size();
	int M = from[0].size();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (from[i][j] != to[i][j])
			{
				return false;
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
	int N, M;
	cin >> N >> M;
	vector<string> from(N), to(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> from[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> to[i];
	}

	/*
		3 * 3 크기의 변환이 가능한 영역에서 맨위, 왼쪽에서부터 검사
		from[i][j]와 to[i][j]가 다르다면
		from[i][j]를 시작으로 하는 3 * 3영역을 뒤집어 주어야 한다.
	*/
	int cnt = 0;
	for (int i = 0; i <= N - 3; ++i)
	{
		for (int j = 0; j <= M - 3; ++j)
		{
			if (from[i][j] != to[i][j])
			{
				reverse(from, i, j);
				++cnt;
			}
		}
	}

	// 두 행렬이 같지 않으면 : 바꿀 수 없는 경우
	if (!check(from, to))
	{
		cnt = -1;
	}

	cout << cnt;

	return 0;
}