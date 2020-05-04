//https://programmers.co.kr/learn/courses/30/lessons/42585
//쇠막대기 
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int stick = 0;

    for (int i = 0; i < arrangement.size(); i++)
    {
        // 막대기 시작
        if (arrangement[i] == '(')
        {
            stick++;
        }
        else
        {
            stick--;

            // 레이저 일때
            if (arrangement[i - 1] == '(')
            {
                answer += stick;
            }
            // 그냥 막대기 끝 일때
            else
            {
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    string arrangement = "()(((()())(())()))(())";
    cout << solution(arrangement);

    return 0;
}