//https://programmers.co.kr/learn/courses/30/lessons/12973
//¦���� �����ϱ�
#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> stack;

    for (int i = 0; i < s.size(); ++i)
    {
        // ������ ��������� push
        if (stack.empty())
        {
            stack.push(s[i]);
        }
        else
        {
            // ������ top�� ���� ���ڰ� ������ pop
            if (stack.top() == s[i])
            {
                stack.pop();
            }
            // �ٸ��ٸ� push
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