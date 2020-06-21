//https://programmers.co.kr/learn/courses/30/lessons/49191
//순위
#include <iostream>

#include <string>
#include <vector>

using namespace std;

enum {LOSE, WIN};

int solution(int n, vector<vector<int>> results) {


    /*
        Floyd-Warshall 알고리즘 활용
    */

    // 승패결과 n * n테이블 만들기
    vector<vector<bool>> table(n, vector<bool>(n, LOSE));
    for (int i = 0; i < results.size(); ++i)
    {
        int winner = results[i][0] - 1;
        int loser = results[i][1] - 1;

        table[winner][loser] = WIN;
    }

    /*
         [from vs to] 결과가 불확실 한 경우
         : [from vs k], [k vs to] 로 확실한 승패를 추론해서 기록
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
                    [from vs to] 우승 : [from vs k], [k vs to] 모두 우승
                    ([from vs to] 패배 : 이미 LOSE로 세팅되어 있다)
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
            // A vs B 둘중 하나가 이겼다면 두 선수의 승패는 확실하다
            if (table[A][B] == WIN || table[B][A] == WIN)
            {
                ++cnt;
            }
        }
        /*
            자기자신을 제외한 나머지 선수와의 승패가 모두 확실하다면
            순위가 확실하므로 known_cnt + 1
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

