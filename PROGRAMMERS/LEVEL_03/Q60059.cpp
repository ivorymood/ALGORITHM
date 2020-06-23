//https://programmers.co.kr/learn/courses/30/lessons/60059
//자물쇠와 열쇠
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int N, M, K;

void rotate(vector<vector<int>> &key)
{
    // 임시 벡터를 활용하여 원본 벡터를 회전시킨다
    vector<vector<int>> tmp(M, vector<int>(M));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            tmp[i][j] = key[i][j];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            key[j][M - 1 - i] = tmp[i][j];
        }
    }
}

bool check(vector<vector<int>> &board, vector<vector<int>> &key, int a, int b)
{
    // board 중앙에 놓여진 자물쇠의 영역의 격자들을 확인한다
    for (int i = M; i < N + M; ++i)
    {
        for (int j = M; j < N + M; ++j)
        {
            int ok = 0;

            // key가 자물쇠 영역에 없다면 자물쇠의 격자값만 확인
            if (i - a < 0 || i - a >= M || j - b < 0 || j - b >= M)
            {
                ok = board[i][j];
            }
            // key가 자물쇠의 영역에 있다면 같은 칸에 위치한 두 값을 확인
            else 
            {
                ok = board[i][j] + key[i - a][j - b];
            }
            
            // 결과가 1이 아니면 실패
            if (ok != 1)
            {
                return false;
            }
        }
    }
    // 자물쇠 모든 격자의 값이 1이 되면 성공
    return true;
}

bool unlock(vector<vector<int>>& board, vector<vector<int>>& key)
{
    /*
        key벡터를 90`씩 총 4번 회전시키고 (0` 포함)
        board에서 이동시킨다
    */
    for (int ltt = 0; ltt < 4; ++ltt)
    {
        for (int i = 0; i <= K - M; ++i)
        {
            for (int j = 0; j <= K - M; ++j)
            {
                /*
                    key[0][0]가 board[i][j]위치로 이동했을 때
                    자물쇠의 모든 홈이 채워지는지 확인
                */
                if (check(board, key, i, j))
                {
                    return true;
                }
            }
        }

        // key 벡터를 90`만큼 회전
        rotate(key);
    }

    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    /*
        -----------------
        |key   key   key|
        |key   lock  key| 
        |key   key   key|
        -----------------
        위와 같은 형태로 lock이 중앙에 들어가도록
        한변 길이 N + 2 * M의 2차배열을 만든다.
    */
    M = key.size();
    N = lock.size();
    K = N + 2 * M;
    
    vector<vector<int>> board(K, vector<int>(K));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i + M][j + M] = lock[i][j];
        }
    }

    // 주어진 키로 자물쇠를 해제할 수 있으면 true반환
    return unlock(board, key);
}

int main()
{
    /*
    vector<vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    */
    vector<vector<int>> key = { {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 1, 1} };
    vector<vector<int>> lock = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    cout << solution(key, lock);

    return 0;
}