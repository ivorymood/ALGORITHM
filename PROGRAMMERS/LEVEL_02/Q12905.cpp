//https://programmers.co.kr/learn/courses/30/lessons/12905
//���� ū ���簢�� ã��

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int max_area = 0;

    int w = board[0].size();
    int h = board.size();

    // board�� �� ���� 2 ������ ���� �����Ƿ�, ��ü�� Ž���Ѵ�.
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            // B[i][j]�� 0���� ũ�� 
            if (board[i][j] > 0)
            {
                // B[i][j]�� 2 * 2 �簢���� ����-�Ʒ��� ĭ�϶�
                if (i >= 1 && j >= 1)
                {
                    // B[i][j]�� ������ 3 ĭ�� �ּҰ� + 1. 
                    // ��ü ���簢���� ���� �� ���̸� ���Ѵ�.
                    board[i][j] = min({ board[i - 1][j], board[i][j - 1], board[i - 1][j - 1] }) + 1;
                }
 
                // �ִ���� ã��
                if (max_area < board[i][j])
                {
                    max_area = board[i][j];
                }
            }
        }
    }

    return max_area * max_area;
}

int main()
{
    /*
    vector<vector<int>> board = { {0,0,1,1} ,{1,1,1,1} };
    */
    vector<vector<int>> board = { {0,1,1,1} ,{1,1,1,1},{1,1,1,1},{0,0,1,0} };

    cout << solution(board);

    return 0;
}