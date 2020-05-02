//https://www.acmicpc.net/problem/3085
#include <iostream>

using namespace std;

const int MAX = 50;

int get_max_after_swap(const char board[][MAX], int N, int x, int y)
{
	int max = 0;

	// ����
	for (int i = x; i < N && i < x + 2; i++)
	{
		int h_max = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (board[i][j] == board[i][j + 1])
			{
				h_max++;
				max = (max < h_max) ? h_max : max;
			}
			else
			{
				h_max = 1;
			}
		}
	}

	// ����
	for (int j = y; j < N && j < y + 2; j++)
	{
		int v_max = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (board[i][j] == board[i + 1][j])
			{
				v_max++;
				max = (max < v_max) ? v_max : max;
			}
			else
			{
				v_max = 1;
			}
		}
	}
	return max;
}

int get_max_count(const char board[][MAX], int N)
{
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		// ����
		int t_max = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (board[i][j] == board[i][j + 1])
			{
				t_max++;
				max = (max < t_max) ? t_max : max;
			}
			else
			{
				t_max = 1;
			}
		}

		// ����
		t_max = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (board[j][i] == board[j + 1][i])
			{
				t_max++;
				max = (max < t_max) ? t_max : max;
			}
			else
			{
				t_max = 1;
			}
		}
	}
	return max;
}

void swap(char* A, char* B)
{
	char tmp = *A;
	*A = *B;
	*B = tmp;
}

int main()
{
	int N;
	cin >> N;
	char board[MAX][MAX] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	// ������ ������ ��ȯ�ϱ� ��, ��ü ���忡�� ���� �ִ밳�� ���ϱ�
	int max = get_max_count(board, N);

	// ������ �� ������ ����/���η� ��ȯ�ϸ鼭 ���� �ִ밳�� ���ϱ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// ����
			if (j < N - 1)
			{
				swap(&board[i][j], &board[i][j + 1]);
				// ��ȯ�� ������ ���Ե� 2*2 ��/�ĸ� �˻�
				int t_max = get_max_after_swap(board, N, i, j);
				swap(&board[i][j], &board[i][j + 1]);
				max = (max < t_max) ? t_max : max;
			}

			// ����
			if (i < N - 1)
			{
				swap(&board[i][j], &board[i + 1][j]);
				// ��ȯ�� ������ ���Ե� 2*2 ��/�ĸ� �˻�
				int t_max = get_max_after_swap(board, N, i, j);
				swap(&board[i][j], &board[i + 1][j]);
				max = (max < t_max) ? t_max : max;
			}
		}
	}

	cout << max;

	return 0;
}