//https://programmers.co.kr/learn/courses/30/lessons/49191
//����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

enum {LOSE, WIN};

int solution(int n, vector<vector<int>> results) {


    /*
        Floyd-Warshall �˰��� Ȱ��
    */

    // ���а�� n * n���̺� �����
    vector<vector<bool>> table(n, vector<bool>(n, LOSE));
    for (int i = 0; i < results.size(); ++i)
    {
        int winner = results[i][0] - 1;
        int loser = results[i][1] - 1;

        table[winner][loser] = WIN;
    }

    /*
         [from vs to] ����� ��Ȯ�� �� ���
         : [from vs k], [k vs to] �� Ȯ���� ���и� �߷��ؼ� ���
     */
    for (int k = 0; k < n; ++k)
    {
        for (int from = 0; from < n; ++from)
        {
            if (table[from][k] == LOSE)
            {
                continue;
            }

            for (int to = 0; to < n; ++to)
            {
                if (table[k][to] == LOSE)
                {
                    continue;
                }

                /*
                    [from vs to] ��� : [from vs k], [k vs to] ��� ���
                    ([from vs to] �й� : �̹� LOSE�� ���õǾ� �ִ�)
                */
                table[from][to] = WIN;
            }
        }
    }

    int certain_cnt = 0;
    for (int A = 0; A < n; ++A)
    {
        int cnt = 0;
        for (int B = 0; B < n; ++B)
        {
            // A vs B ���� �ϳ��� �̰�ٸ� �� ������ ���д� Ȯ���ϴ�
            if (table[A][B] == WIN || table[B][A] == WIN)
            {
                ++cnt;
            }
        }
        /*
            �ڱ��ڽ��� ������ ������ �������� ���а� ��� Ȯ���ϴٸ�
            ������ Ȯ���ϹǷ� known_cnt + 1
        */
        if (cnt == n - 1)
        {
            ++certain_cnt;
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

