//https://programmers.co.kr/learn/courses/30/lessons/64061
//ũ���� �����̱� ���� 
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	
	stack<int> basket;
	int cnt = 0;

	// moves ���� ����
	for (int i = 0; i < moves.size(); i++)
	{
		// ũ���� ��ġ
		int crane_pos = moves[i] - 1;

		// ���� ���������� ���� ���翩�� Ȯ��
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][crane_pos] != 0)
			{
				int doll = board[j][crane_pos];

				// �ٱ��ϰ� ������� �ʰ�, top�� ���� ������ ������ pop && ī����
				if (!basket.empty() && basket.top() == doll)
				{
					basket.pop();
					cnt += 2;
				}
				// �׷��� ������ �ٱ��Ͽ� push
				else
				{
					basket.push(doll);
				}
				
				// ���ڿ��� ���� �����ڸ� ����ֱ�
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