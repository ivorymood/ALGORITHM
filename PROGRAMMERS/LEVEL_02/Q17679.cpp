//https://programmers.co.kr/learn/courses/30/lessons/17679
//������4���
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��� ���ŭ �ű��, ���� ���� ��ȯ
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
    // �������� ����� üũ�� bool 2���� ����
    vector<vector<bool>> visited(M, vector<bool>(N));

    for (int i = 0; i < M - 1; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            // ������ ����� �ƴϸ�
            if (board[i][j])
            {
                // ������, �Ʒ���, �����Ʒ��� ����� ���� ��ϰ� ������
                if (board[i][j] == board[i][j + 1]
                    && board[i][j] == board[i + 1][j]
                    && board[i][j] == board[i + 1][j + 1])
                {
                    // �������� ��� üũ
                    visited[i][j] = true;
                    visited[i][j + 1] = true;
                    visited[i + 1][j] = true;
                    visited[i + 1][j + 1] = true;
                }
            }
        }
    }

    // ���� ��ϰ��� ���ϱ�
    int cnt = remove_n_move(board, visited, M, N);
    
    // ���̻� ���� ����� ������ �հ� ��ȯ. 
    if (cnt == 0)
    {
        return sum;
    }
    // �հ迡 ���� ��ϰ����� ���ؼ� ���ȣ��
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