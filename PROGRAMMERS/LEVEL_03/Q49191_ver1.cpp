//https://programmers.co.kr/learn/courses/30/lessons/49191
//순위
#include <iostream>

#include <string>
#include <vector>

using namespace std;

enum { LOSE = -1, UNKNOWN, WIN };

int solution(int n, vector<vector<int>> results) {

    /*
        Floyd-Warshall 알고리즘 활용
    */

    // 승패결과 n * n테이블 만들기
    vector<vector<int>> table(n, vector<int>(n, UNKNOWN));
    for (int i = 0; i < results.size(); ++i)
    {
        int winner = results[i][0] - 1;
        int loser = results[i][1] - 1;

        table[winner][loser] = WIN;
        table[loser][winner] = LOSE;
    }

    /*
        [from vs to] 결과가 불확실 한 경우
        : [from vs k], [k vs to] 로 확실한 승패를 추론해서 기록
    */
    for (int k = 0; k < n; ++k)
    {
        for (int from = 0; from < n; ++from)
        {
            // [from vs k]결과가 확실하지 않으면
            if (table[from][k] == UNKNOWN)
            {
                continue;
            }

            for (int to = 0; to < n; ++to)
            {
                // [k vs to]결과가 확실하지 않으면
                if (table[k][to] == UNKNOWN)
                {
                    continue;
                }

                /*
                    [from vs to] 우승 : [from vs k], [k vs to] 모두 우승
                    [from vs to] 패배 : [from vs k], [k vs to] 모두 패배
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
                확실하지 않은 승패가 있다면 
                순위가 확정되지 않은 것이므로 certain_cnt - 1
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

