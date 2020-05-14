//https://programmers.co.kr/learn/courses/30/lessons/12905
//가장 큰 정사각형 찾기

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int max_area = 0;

    int w = board[0].size();
    int h = board.size();

    // board의 양 변이 2 이하일 수도 있으므로, 전체를 탐색한다.
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            // B[i][j]가 0보다 크면 
            if (board[i][j] > 0)
            {
                // B[i][j]가 2 * 2 사각형의 오른-아래쪽 칸일때
                if (i >= 1 && j >= 1)
                {
                    // B[i][j]는 나머지 3 칸의 최소값 + 1. 
                    // 전체 정사각형의 가장 긴 길이를 뜻한다.
                    board[i][j] = min({ board[i - 1][j], board[i][j - 1], board[i - 1][j - 1] }) + 1;
                }
 
                // 최대길이 찾기
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