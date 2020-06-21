//https://programmers.co.kr/learn/courses/30/lessons/49191
//����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

enum { LOSE = -1, UNKNOWN, WIN };

int solution(int n, vector<vector<int>> results) {

    /*
        Floyd-Warshall �˰��� Ȱ��
    */

    // ���а�� n * n���̺� �����
    vector<vector<int>> table(n, vector<int>(n, UNKNOWN));
    for (int i = 0; i < results.size(); ++i)
    {
        int winner = results[i][0] - 1;
        int loser = results[i][1] - 1;

        table[winner][loser] = WIN;
        table[loser][winner] = LOSE;
    }

    /*
        [from vs to] ����� ��Ȯ�� �� ���
        : [from vs k], [k vs to] �� Ȯ���� ���и� �߷��ؼ� ���
    */
    for (int k = 0; k < n; ++k)
    {
        for (int from = 0; from < n; ++from)
        {
            // [from vs k]����� Ȯ������ ������
            if (table[from][k] == UNKNOWN)
            {
                continue;
            }

            for (int to = 0; to < n; ++to)
            {
                // [k vs to]����� Ȯ������ ������
                if (table[k][to] == UNKNOWN)
                {
                    continue;
                }

                /*
                    [from vs to] ��� : [from vs k], [k vs to] ��� ���
                    [from vs to] �й� : [from vs k], [k vs to] ��� �й�
                */
                if (table[from][k] == table[k][to])
                {
                    table[from][to] = table[from][k];
                }
            }
        }
    }

    int certain_cnt = n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                continue;
            }

            /*
                Ȯ������ ���� ���а� �ִٸ� 
                ������ Ȯ������ ���� ���̹Ƿ� certain_cnt - 1
            */
            if (table[i][j] == UNKNOWN)
            {
                --certain_cnt;
                break;
            }
        }
    }
    return certain_cnt;
}

int main()
{
    int n = 5; vector<vector<int>> results = { {4, 3},{4, 2},{3, 2},{1, 2},{2, 5} };

    cout << solution(n, results);

    return 0;
}

