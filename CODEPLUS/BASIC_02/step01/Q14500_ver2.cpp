//https://www.acmicpc.net/problem/14500
#include <iostream>
#include <algorithm>

using namespace std;

// 테트로미노 위치값
int ttrmn[19][3][2] = {
	// Type A - 가로
	{{0,1}, {0,2}, {0,3}},
	// Type A - 세로
	{{1,0}, {2,0}, {3,0}},
	// Type B
	{{0,1}, {1,0}, {1,1}},
	// Type C - 가로
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {0,2}, {1,2}},
	{{0,1}, {0,2}, {1,0}},
	// Type C - 세로
	{{1,0}, {2,0}, {0,1}},
	{{1,0}, {2,0}, {2,1}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {-1,1}, {-2,1}},
	// Type D - 가로 
	{{0,1}, {1,1}, {1,2}},
	{{0,1}, {-1,1}, {-1,2}},
	// Type D - 세로
	{{1,0}, {1,1}, {2,1}},
	{{1,0}, {0,1}, {-1,1}},
	// Type E - 가로
	{{0,1}, {0,2}, {1,1}},
	{{0,1}, {0,2}, {-1,1}},
	// Type E - 세로
	{{1,0}, {2,0}, {1,1}},
	{{1,0}, {2,0}, {1,-1}},
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 500;
	int board[MAX][MAX];

	// 입력
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	// 테트로미노 최대값 구하기
	int t_max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 현재위치에서 가능한 19가지 유형 테트로미노의 최대값
			for (int k = 0; k < 19; k++)
			{
				int t = board[i][j];
				bool possible = true;
				for (int l = 0; l < 3; l++)
				{
					// 위치값
					int y = i + ttrmn[k][l][0];
					int x = j + ttrmn[k][l][1];
				
					if (0 <= y && y < N && 0 <= x && x < M)
					{
						t += board[y][x];
					}
					else
					{
						possible = false;
						break;
					}
				}

				// 테트로미노 완성가능하면 최대값 교환
				if (possible)
				{
					t_max = max(t_max, t);
				}
			}
		}
	}

	cout << t_max;

	return 0;
}