//https://programmers.co.kr/learn/courses/30/lessons/17679
//프렌즈4블록
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 블록 지운만큼 옮기고, 지운 개수 반환
int remove_n_move(vector<string>& board, vector<vector<bool>> &visited, int M, int N)
{
    int removed = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j])
            {
                for (int k = i - 1; k >= 0; --k)
                {
                    board[k + 1][j] = board[k][j];
                    board[k][j] = 0;
                }
                ++removed;
            }
        }
    }
    return removed;
}

int remove_block(vector<string>& board, int sum, int M, int N)
{
    // 지워야할 블록을 체크할 bool 2차원 벡터
    vector<vector<bool>> visited(M, vector<bool>(N));

    for (int i = 0; i < M - 1; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            // 지워진 블록이 아니면
            if (board[i][j])
            {
                // 오른쪽, 아래쪽, 오른아래쪽 블록이 현재 블록과 같으면
                if (board[i][j] == board[i][j + 1]
                    && board[i][j] == board[i + 1][j]
                    && board[i][j] == board[i + 1][j + 1])
                {
                    // 지워야할 블록 체크
                    visited[i][j] = true;
                    visited[i][j + 1] = true;
                    visited[i + 1][j] = true;
                    visited[i + 1][j + 1] = true;
                }
            }
        }
    }

    // 지운 블록개수 구하기
    int cnt = remove_n_move(board, visited, M, N);
    
    // 더이상 지울 블록이 없으면 합계 반환. 
    if (cnt == 0)
    {
        return sum;
    }
    // 합계에 지운 블록개수를 더해서 재귀호출
    return remove_block(board, sum + cnt, M, N);
}

int solution(int m, int n, vector<string> board) {

    return remove_block(board, 0, m, n);
}

int main()
{
    
    /*
    int m = 4, n = 5;
    vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
     int m = 6, n = 6; 
    vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA" , "TTMMMF", "TMMTTJ"};
    */

    int m = 8, n = 5;
    vector<string> board = {"HGNHU" , "CRSHV", "UKHVL", "MJHQB" , "GSHOT", "MQMJJ", "AGJKK", "QULKK"};
   
    cout << solution(m, n, board);

    return 0;
}