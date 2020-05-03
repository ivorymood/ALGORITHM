//https://www.acmicpc.net/problem/14500
#include <iostream>
#include <algorithm>

using namespace std;

// ��Ʈ�ι̳� ��ġ��
int ttrmn[19][3][2] = {
	// Type A - ����
	{{0,1}, {0,2}, {0,3}},
	// Type A - ����
	{{1,0}, {2,0}, {3,0}},
	// Type B
	{{0,1}, {1,0}, {1,1}},
	// Type C - ����
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {0,2}, {1,2}},
	{{0,1}, {0,2}, {1,0}},
	// Type C - ����
	{{1,0}, {2,0}, {0,1}},
	{{1,0}, {2,0}, {2,1}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {-1,1}, {-2,1}},
	// Type D - ���� 
	{{0,1}, {1,1}, {1,2}},
	{{0,1}, {-1,1}, {-1,2}},
	// Type D - ����
	{{1,0}, {1,1}, {2,1}},
	{{1,0}, {0,1}, {-1,1}},
	// Type E - ����
	{{0,1}, {0,2}, {1,1}},
	{{0,1}, {0,2}, {-1,1}},
	// Type E - ����
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

	// �Է�
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	// ��Ʈ�ι̳� �ִ밪 ���ϱ�
	int t_max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// ������ġ���� ������ 19���� ���� ��Ʈ�ι̳��� �ִ밪
			for (int k = 0; k < 19; k++)
			{
				int t = board[i][j];
				bool possible = true;
				for (int l = 0; l < 3; l++)
				{
					// ��ġ��
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

				// ��Ʈ�ι̳� �ϼ������ϸ� �ִ밪 ��ȯ
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