//https://programmers.co.kr/learn/courses/30/lessons/60059
//�ڹ���� ����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int N, M, K;

void rotate(vector<vector<int>> &key)
{
    // �ӽ� ���͸� Ȱ���Ͽ� ���� ���͸� ȸ����Ų��
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
    // board �߾ӿ� ������ �ڹ����� ������ ���ڵ��� Ȯ���Ѵ�
    for (int i = M; i < N + M; ++i)
    {
        for (int j = M; j < N + M; ++j)
        {
            int ok = 0;

            // key�� �ڹ��� ������ ���ٸ� �ڹ����� ���ڰ��� Ȯ��
            if (i - a < 0 || i - a >= M || j - b < 0 || j - b >= M)
            {
                ok = board[i][j];
            }
            // key�� �ڹ����� ������ �ִٸ� ���� ĭ�� ��ġ�� �� ���� Ȯ��
            else 
            {
                ok = board[i][j] + key[i - a][j - b];
            }
            
            // ����� 1�� �ƴϸ� ����
            if (ok != 1)
            {
                return false;
            }
        }
    }
    // �ڹ��� ��� ������ ���� 1�� �Ǹ� ����
    return true;
}

bool unlock(vector<vector<int>>& board, vector<vector<int>>& key)
{
    /*
        key���͸� 90`�� �� 4�� ȸ����Ű�� (0` ����)
        board���� �̵���Ų��
    */
    for (int ltt = 0; ltt < 4; ++ltt)
    {
        for (int i = 0; i <= K - M; ++i)
        {
            for (int j = 0; j <= K - M; ++j)
            {
                /*
                    key[0][0]�� board[i][j]��ġ�� �̵����� ��
                    �ڹ����� ��� Ȩ�� ä�������� Ȯ��
                */
                if (check(board, key, i, j))
                {
                    return true;
                }
            }
        }

        // key ���͸� 90`��ŭ ȸ��
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
        ���� ���� ���·� lock�� �߾ӿ� ������
        �Ѻ� ���� N + 2 * M�� 2���迭�� �����.
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

    // �־��� Ű�� �ڹ��踦 ������ �� ������ true��ȯ
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