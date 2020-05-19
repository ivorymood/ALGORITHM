//https://programmers.co.kr/learn/courses/30/lessons/12973
//짝지어 제거하기
#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stack;

    for (int i = 0; i < s.size(); ++i)
    {
        // 스택이 비어있으면 push
        if (stack.empty())
        {
            stack.push(s[i]);
        }
        else
        {
            // 스택의 top과 현재 문자가 같으면 pop
            if (stack.top() == s[i])
            {
                stack.pop();
            }
            // 다르다면 push
            else
            {
                stack.push(s[i]);
            }
        }
    }

    return stack.empty();
}

int main()
{
    /*
    string s = "baabaa";
    */
    string s = "cdcd";

    cout << solution(s);

    return 0;
}