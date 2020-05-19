//https://programmers.co.kr/learn/courses/30/lessons/12951
//JadenCase 문자열 만들기
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    for (int i = 0; i < s.size(); ++i)
    {
        // 맨 앞이거나 공백 뒤의 첫 글자는 대문자
        if (i == 0 || s[i - 1] == ' ')
        {
            s[i] = toupper(s[i]);
        }
        // 그 외는 소문자
        else
        {
            s[i] = tolower(s[i]);
        }
    }

    return s;
}

int main()
{
    /*
    string s = "3people unFollowed me";
    */
    string s = "for the last week";

    cout << solution(s);

    return 0;
}