//https://www.acmicpc.net/problem/4574
#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
int dr_x[] = {0, 1};
int dr_y[] = {1, 0};
vector<vector<bool>> vert;
vector<vector<bool>> hori;
vector<vector<bool>> box;
vector<vector<bool>> domino;
vector<vector<int>> sdoku;

void print_sdoku()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << sdoku[i][j];
		}
		cout << '\n';
	}
}

int inline bx(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

void inline change_flag(int x, int y, int order, bool flag)
{
	vert[x][order] = hori[y][order] = box[bx(x, y)][order] = flag;
}

bool inline possible(int x, int y, int order)
{
	return !(vert[x][order] || hori[y][order] || box[bx(x, y)][order]);
}

bool sdominoku(int num)
{
	// ������ ĭ�� ä��� ��� �� ����
	if (num == N * N)
	{
		print_sdoku();
		return true;
	}

	// ������ ���� ��/�� ���ϱ�
	int x = num / N;
	int y = num % N;
	
	// ĭ�� ������� ���� �� : ���� ĭ���� sdominoku����Լ� ȣ��
	if (sdoku[x][y] != 0)
	{
		return sdominoku(num + 1);
	}
	// ĭ�� ������� ��
	else
	{
		// ���̳� ���� ���� 2���� Ž��
		for (int i = 0; i < 2; ++i)
		{
			int x2 = x + dr_x[i];
			int y2 = y + dr_y[i];

			// ���� ���̰ų� ���̳� 2��° ĭ�� 0�� �ƴϸ� continue
			if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N || sdoku[x2][y2] != 0)
			{
				continue;
			}
			
			// ������ ���̳� ������ �ڸ��� �����ϱ�
			for (int fst = 1; fst <= N; ++fst)
			{
				for (int snd = 1; snd <= N; ++snd)
				{
					// ���̳��� �� ���ڰ� ���ų� �̹� ����� ���̳� �����̸� continue
					if (fst == snd || domino[fst][snd])
					{
						continue;
					}

					// �� �ڸ��� �� ���ڰ� �������� ������ ��
					if (possible(x, y, fst) && possible(x2, y2, snd))
					{
						// ���� ���� �� ������, ���̳� bool���� true üũ
						sdoku[x][y] = fst;
						sdoku[x2][y2] = snd;
						change_flag(x, y, fst, true);
						change_flag(x2, y2, snd, true);
						domino[fst][snd] = domino[snd][fst] = true;

						// �ѹ��̶� ������Ű�� ����
						if (sdominoku(num + 1)) return true;

						// ���� ���� �� ������, ���̳� bool���� false üũ
						sdoku[x][y] = sdoku[x2][y2] = 0;
						change_flag(x, y, fst, false);
						change_flag(x2, y2, snd, false);
						domino[fst][snd] = domino[snd][fst] = false;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int puzzle = 0;
	while (true)
	{
		int cnt;
		cin >> cnt;
		if (cnt == 0)
		{
			break;
		}

		// �� ���� �ʱ�ȭ
		domino = vector<vector<bool>>(N + 1, vector<bool>(N + 1));
		vert = vector<vector<bool>>(N, vector<bool>(N + 1));
		hori = vector<vector<bool>>(N, vector<bool>(N + 1));
		box = vector<vector<bool>>(N, vector<bool>(N + 1));
		sdoku = vector<vector<int>>(N, vector<int>(N));
		
		// �Է� - ���̳� & ������
		while (cnt--)
		{
			int n1, n2;
			string p1, p2;
			cin >> n1 >> p1 >> n2 >> p2;

			// ������ �ǿ� ���� �Է�
			int x1 = p1[0] - 'A', x2 = p2[0] - 'A';
			int y1 = p1[1] - '1', y2 = p2[1] - '1';
			sdoku[x1][y1] = n1;
			sdoku[x2][y2] = n2;
			
			// ������, ���̳� bool���Ϳ� true üũ
			vert[x1][n1] = vert[x2][n2] = true;
			hori[y1][n1] = hori[y2][n2] = true;
			box[(x1 / 3) * 3 + (y1 / 3)][n1] = true;
			box[(x2 / 3) * 3 + (y2 / 3)][n2] = true;
			domino[n1][n2] = domino[n2][n1] = true;
		}

		// �Է� - ������
		for (int i = 1; i <= N; ++i)
		{
			string pos;
			cin >> pos;

			// ������ �ǿ� ���� �Է�
			int x = pos[0] - 'A';
			int y = pos[1] - '1';
			sdoku[x][y] = i;

			// ������ bool���Ϳ� true üũ
			vert[x][i] = hori[y][i] = true;
			box[(x / 3) * 3 + (y / 3)][i] = true;
		}


		// �����̳��� �ϼ� �� ���
		cout << "Puzzle " << ++puzzle << '\n';
		sdominoku(0);
	}

	return 0;
}