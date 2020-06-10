//https://www.acmicpc.net/problem/9663
#include <iostream>

using  namespace std;

const int MAX = 15;
bool ck_col[MAX];
bool ck_left_diag[MAX * 2];
bool ck_right_diag[MAX * 2];
int N, cnt;

bool possible(int row, int col)
{
	if (ck_col[col] || ck_left_diag[row + col] || ck_right_diag[row - col + N])
	{
		return false;
	}
	return true;
}

void change_flag(int row, int col, bool flag)
{
	ck_col[col] = flag;
	ck_left_diag[row + col] = flag;
	ck_right_diag[row - col + N] = flag;
}

void go(int row)
{
	// N���� �� �ڸ��� �������� ī���� �� ����
	if (row == N)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// ������� ������ ���� ������ �� ���� ��ġ�̸�
		if(possible(row, i))
		{
			// (row, i)�� ��, ������ �밢��, ������ �밢�� ���� true �÷��� üũ�ϱ�
			change_flag(row, i, true);
			
			// �������� ���� ���ϱ� ���� go�Լ� ���ȣ��
			go(row + 1);
			
			// (row, i)�� ��, ������ �밢��, ������ �밢�� ���� false �÷��� üũ�ϱ�
			change_flag(row, i, false);
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

	// N�� ���� ���� ������ �� ������ �ϴ� ����� �� ���ϱ�
	go(0);

	// ���
	cout << cnt;

	return 0;
}