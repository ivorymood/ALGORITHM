//https://programmers.co.kr/learn/courses/30/lessons/64061
//크레인 인형뽑기 게임 
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	
	stack<int> basket;
	int cnt = 0;

	// moves 동작 수행
	for (int i = 0; i < moves.size(); i++)
	{
		// 크레인 위치
		int crane_pos = moves[i] - 1;

		// 상자 위에서부터 인형 존재여부 확인
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][crane_pos] != 0)
			{
				int doll = board[j][crane_pos];

				// 바구니가 비어있지 않고, top이 집은 인형과 같으면 pop && 카운팅
				if (!basket.empty() && basket.top() == doll)
				{
					basket.pop();
					cnt += 2;
				}
				// 그렇지 않으면 바구니에 push
				else
				{
					basket.push(doll);
				}
				
				// 상자에서 집은 인형자리 비워주기
				board[j][crane_pos] = 0;

				break;
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> board 
		= { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	cout << solution(board, moves);

	return 0;
}