//https://programmers.co.kr/learn/courses/30/lessons/42841?language=cpp
//숫자 야구
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int const MAX = 3;
vector<vector<int>> testcase;
int cnt;

/*
    주어진 테스트 케이스를 다 만족하는지 검사하기

    각 테스트 숫자를 정답숫자와 비교하여 n스트라이크 m볼이 나왔다면, 
    역으로 정답숫자도 각 테스트 숫자와 비교하면 n스트라이크 m볼이 나올 것.
*/
bool possible(int num)
{
    for (int i = 0; i < testcase.size(); i++)
    {
        if (num == testcase[i][0])
        {
            return false;
        }

        int strike = 0;
        int ball = 0;
        string str_num = to_string(num);
        string str_test = to_string(testcase[i][0]);

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (str_num[i] == str_test[j])
                {
                    if (i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }

        if (strike != testcase[i][1] || ball != testcase[i][2])
        {
            return false;
        }
    }

    return true;
}

void perm(int output, bool visited[], int depth, int r)
{
    // depth가 3에 도달하면 만들어진 숫자 검사
    if (depth == r)
    {
        if (possible(output))
        {
            cnt++;
        }
        return;
    }

    // 1~9까지의 서로 다른 수로 3자리수 만들기
    for (int i = 1; i <= 9; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            output = output * 10 + i;
            perm(output, visited, depth + 1, r);
            output /= 10;
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> baseball) {

    // 전역vector와 포인터 교환
    testcase.swap(baseball);

    bool visited[10] = { 0, };

    // 3자리의 숫자를 조합한 후, 주어진 조건 충족여부를 검사하기
    perm(0, visited, 0, 3);

    return cnt;
}

int main()
{
    vector<vector<int>> baseball = { {123, 1, 1} ,{356, 1, 0},{327, 2, 0},{489, 0, 1} };

    cout << solution(baseball);

    return 0;
}