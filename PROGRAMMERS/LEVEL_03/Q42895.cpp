//https://programmers.co.kr/learn/courses/30/lessons/42895
//N으로 표현
#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX = 8;

// aim을 만드는 N의 최소 개수를 반환
int go(vector<unordered_set<int>>& v_set, int cnt, int aim)
{
    // 개수가 8 초과이면 -1 반환
    if (cnt > MAX)
    {
        return -1;
    }

    /*
        두 숫자를 이루는 N의 개수가 cnt개인 set들의 숫자로 사칙연산 후
        만들어진 숫자를 v_set[cnt]에 insert
        
        ex) cnt = 3 일때, v_set[1]의 숫자들 ~ v_set[2]의 숫자들 연산 결과를 v_set[3]에 insert
                          v_set[2]의 숫자들 ~ v_set[1]의 숫자들 연산 결과를 v_set[3]에 insert
    */
    for (int i = 1; i < cnt; ++i)
    {
        for (int num1 : v_set[i])
        {
            for (int num2 : v_set[cnt - i])
            {
                v_set[cnt].insert(num1 + num2);
                v_set[cnt].insert(num1 - num2);
                v_set[cnt].insert(num1 * num2);

                if (num2 != 0)
                {
                    v_set[cnt].insert(num1 / num2);
                }
            }
        }
    }

    // v_set[cnt]에서 목표한 숫자를 찾으면 cnt반환 (= 최소 개수)
    if (v_set[cnt].find(aim) != v_set[cnt].end())
    {
        return cnt;
    }

    // 찾지 못했다면 cnt + 1로 go함수 재귀호출
    return go(v_set, cnt + 1, aim);
}

int solution(int N, int number) {
   
    // v_set[cnt] : N을 cnt번 사용한 숫자들의 set
    vector<unordered_set<int>> v_set(MAX + 1);
    
    /*
        숫자 N, NN, NNN ... NNNNNNNN을 미리 각 집합에 넣어줌.
        
        ex) N은 v_set[1]에, NNN은 v_set[3]에 insert
    */
    int base = 0;
    for (int i = 1; i <= MAX; ++i)
    {
        base = base * 10 + N;
        v_set[i].insert(base);
    }

    // number를 만드는 N의 최소 개수를 반환. 개수가 8 초과이면 -1 반환
    return go(v_set, 2, number);
}

int main()
{
    /*
    int N = 5; int number = 12; 
    int N = 5; int number = 31168;
    */
    int N = 2; int number = 11;

    cout << solution(N, number);

    return 0;
}