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
	// N개의 퀸 자리가 정해지면 카운팅 후 종료
	if (row == N)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		// 현재까지 정해진 퀸이 공격할 수 없는 위치이면
		if(possible(row, i))
		{
			// (row, i)의 열, 좌하향 대각선, 우하향 대각선 벡터 true 플래그 체크하기
			change_flag(row, i, true);
			
			// 다음행의 퀸을 정하기 위해 go함수 재귀호출
			go(row + 1);
			
			// (row, i)의 열, 좌하향 대각선, 우하향 대각선 벡터 false 플래그 체크하기
			change_flag(row, i, false);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;

	// N개 퀸이 서로 공격할 수 없도록 하는 경우의 수 구하기
	go(0);

	// 출력
	cout << cnt;

	return 0;
}