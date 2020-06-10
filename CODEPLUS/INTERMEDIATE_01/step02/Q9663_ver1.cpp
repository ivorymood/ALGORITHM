//https://www.acmicpc.net/problem/9663
#include <iostream>
#include <vector>

using  namespace std;

// ���� �̵������� 8����
int dr_x[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dr_y[] = {1, 1, 0, -1, -1, -1, 0, 1};
int N, cnt;

// ���� ���� ������ ������ ���� +num �ϱ�
void check_8_ways(vector<vector<int>>& check, int x, int y, int num)
{
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dr_x[i];
		int ny = y + dr_y[i];

		while (!(nx < 0 || nx >= N || ny < 0 || ny >= N))
		{
			check[nx][ny] += num;
			nx += dr_x[i];
			ny += dr_y[i];
		}
	}
}

void go(vector<vector<int>>& check, int row)
{
	// N���� �� �ڸ��� �������� ī���� �� ����
	if (row == N)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// ������� ������ ���� ���ݰ����� ������ �ƴϸ�
		if (check[row][i] == 0)
		{
			// �����������κ��� ���� ���ݰ����� ��� ������ +1
			check_8_ways(check, row, i, 1);
			
			// �������� ���� ���ϱ� ���� go�Լ� ���ȣ��
			go(check, row + 1);
			
			// �����������κ��� ���� ���ݰ����� ��� ������ -1
			check_8_ways(check, row, i, -1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N;
	vector<vector<int>> check(N, vector<int>(N));

	// N�� ���� ���� ������ �� ������ �ϴ� ����� �� ���ϱ�
	go(check, 0);

	// ���
	cout << cnt;

	return 0;
}