//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 25;
bool check[N_MAX][N_MAX];
int dic_x[4] = { 0, 1, 0, -1 };
int dic_y[4] = { 1, 0, -1, 0 };

// ���� �켱 Ž��
void dfs(vector<vector<int>> &apt, vector<int> &cmplx, int x, int y)
{
	// ���� ������ cmplx �ε���
	int now = cmplx.size() - 1;
	int N = apt.size();

	// ����, �Ʒ�, ��, �� 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		int newX = x + dic_x[i];
		int newY = y + dic_y[i];

		// apt �ε����� ���� �ȿ� �ְ�
		if (0 <= newY && newY < N && 0 <= newX && newX < N)
		{
			// ���� �湮�ϱ� ��, ���� 1�� ���̸� dfs�Լ� ��� ȣ��
			if (!check[newX][newY] && apt[newX][newY] > 0)
			{
				// ���� ������ cmplx �ε����� �� + 1
				++cmplx[now];
				check[newX][newY] = true;
				dfs(apt, cmplx, newX, newY);
			}
		}
	}
}

int main()
{
	// �Է�
	int N;
	scanf("%d", &N);
	vector<vector<int>> apt(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%1d", &apt[i][j]);
		}
	}

	// apt Ž��
	vector<int> cmplx;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// ���� �湮�ϱ� ��, ���� 1�� apt[i][j]���� ���̿켱 Ž���� �Ѵ�
			if (!check[i][j] && apt[i][j] > 0)
			{
				check[i][j] = true;
				cmplx.push_back(1);
				dfs(apt, cmplx, i, j);
			}
		}
	}

	// �������� ����
	sort(cmplx.begin(), cmplx.end());

	// ���
	cout << cmplx.size() << '\n';
	for (int i : cmplx)
	{
		cout << i << '\n';
	}

	return 0;
}