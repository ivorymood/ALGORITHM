//https://programmers.co.kr/learn/courses/30/lessons/12951
//JadenCase ���ڿ� �����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    for (int i = 0; i < s.size(); ++i)
    {
        // �� ���̰ų� ���� ���� ù ���ڴ� �빮��
        if (i == 0 || s[i - 1] == ' ')
        {
            s[i] = toupper(s[i]);
        }
        // �� �ܴ� �ҹ���
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