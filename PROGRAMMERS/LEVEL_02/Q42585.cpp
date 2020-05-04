//https://programmers.co.kr/learn/courses/30/lessons/42585
//�踷��� 
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int stick = 0;

    for (int i = 0; i < arrangement.size(); i++)
    {
        // ����� ����
        if (arrangement[i] == '(')
        {
            stick++;
        }
        else
        {
            stick--;

            // ������ �϶�
            if (arrangement[i - 1] == '(')
            {
                answer += stick;
            }
            // �׳� ����� �� �϶�
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