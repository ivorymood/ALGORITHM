//https://www.acmicpc.net/problem/12100
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIMIT = 5;
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};
enum {RIGHT, DOWN, LEFT, UP};
int N;

struct block {
	int val;
	bool cllpsd;
};

void move_updown(vector<vector<block>>& board, int dir)
{
	// 시작/끝 인덱스 지정
	int strt = 0;
	int end = N;
	int p = 1;
	if (dir == DOWN)
	{
		strt = N - 1;
		end = -1;
		p = -1;
	}

	while (true)
	{
		bool moved = false;
		
		for (int j = 0; j < N; ++j)
		{
			for (int i = strt + p; i != end; i += p)
			{
				// 2번째 블럭값이 0이면 continue
				if (board[i][j].val == 0)
				{
					continue;
				}
				// 1번째 블럭값이 0이면 : 2번째 블럭 -> 1번째로 이동
				if (board[i - p][j].val == 0)
				{
					board[i - p][j].val = board[i][j].val;
					board[i - p][j].cllpsd = board[i][j].cllpsd;
					board[i][j].val = 0;
					moved = true;
				}
				// 1번째 블럭값이 2번째 블럭값과 같으면
				else if (board[i - p][j].val == board[i][j].val)
				{
					// 둘다 아직 합쳐지지 않았으면 
					// : 1번째 블럭값 2배, bool 체크. 2번째 블럭값 0 변경
					if (board[i - p][j].cllpsd == false && board[i][j].cllpsd == false)
					{
						board[i - p][j].val *= 2;
						board[i - p][j].cllpsd = true;
						board[i][j].val = 0;
						moved = true;
					}
				}
			}
		}

		if (!moved)
		{
			break;
		}
	}
}

void move_leftright(vector<vector<block>>& board, int dir)
{
	// 시작/끝 인덱스 지정
	int strt = 0;
	int end = N;
	int p = 1;
	if (dir == RIGHT)
	{
		strt = N - 1;
		end = -1;
		p = -1;
	}

	while (true)
	{
		bool moved = false;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = strt + p; j != end; j += p)
			{
				// 2번째 블럭값이 0이면 continue
				if (board[i][j].val == 0)
				{
					continue;
				}

				// 1번째 블럭값이 0이면 : 2번째 블럭 -> 1번째로 이동
				if (board[i][j - p].val == 0)
				{
					board[i][j - p].val = board[i][j].val;
					board[i][j - p].cllpsd = board[i][j].cllpsd;
					board[i][j].val = 0;
					moved = true;
				}
				// 1번째 블럭값이 2번째 블럭값과 같으면
				else if (board[i][j - p].val == board[i][j].val)
				{
					// 둘다 아직 합쳐지지 않았으면 
					// : 1번째 블럭값 2배, bool 체크. 2번째 블럭값 0 변경
					if (board[i][j - p].cllpsd == false && board[i][j].cllpsd == false)
					{
						board[i][j - p].val *= 2;
						board[i][j - p].cllpsd = true;
						board[i][j].val = 0;
						moved = true;
					}
				}
			}
		}

		if (!moved)
		{
			break;
		}
	}
}

int get_max_block(vector<vector<block>>& board)
{
	int max_block = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (max_block < board[i][j].val)
			{
				max_block = board[i][j].val;
			}
		}
	}
	return max_block;
}

void print(vector<vector<block>>& board) {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j].val << ' ';
		}
		cout << '\n';
	}
}

int dfs(vector<vector<block>>& board, int cnt)
{
	// LIMIT번 이동했으면 블록의 최대값 리턴
	if (cnt == LIMIT)
	{
		return get_max_block(board);
	}

	// bool 플래그 false 세팅
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			board[i][j].cllpsd = false;
		}
	}

	int max_block = 0;

	// 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		// 이전 방향 움직임과 독립적인 보드 생성
		vector<vector<block>> new_board(N, vector<block>(N));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				new_board[i][j].val = board[i][j].val;
			}
		}

		// 왼/오 이동
		if (i == RIGHT || i == LEFT)
		{
			move_leftright(new_board, i);
		}
		// 위/아래 이동
		else if (i == DOWN || i == UP)
		{
			move_updown(new_board, i);
		}
		
		// dfs 재귀함수 호출 및 블록 최대값 구하기
		max_block = max(dfs(new_board, cnt + 1), max_block);
	}

	return max_block;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> N;
	vector<vector<block>> board(N, vector<block>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j].val;
		}
	}

	// 블록 최대값 출력
	cout << dfs(board, 0);

	return 0;
}