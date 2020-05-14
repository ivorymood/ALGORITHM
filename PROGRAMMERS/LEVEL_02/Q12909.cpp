//https://programmers.co.kr/learn/courses/30/lessons/12909
//올바른 괄호
#include <iostream>

#include<string>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            ++cnt;
        }
        else
        {
            --cnt;
        }

        if (cnt < 0)
        {
            return false;
        }
    }

    return cnt == 0;
}

int main()
{
    string s = "(())()";
    /*
    string s = "()()";
    string s = ")()(";
    string s = "(()(";
    */

    cout << solution(s);

    return 0;
}