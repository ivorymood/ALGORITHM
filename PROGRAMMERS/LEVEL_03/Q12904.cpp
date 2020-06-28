//https://programmers.co.kr/learn/courses/30/lessons/12904
//가장 긴 팰린드롬
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int get_pldr_len(const string &s, int left, int right)
{
    int pldr = right - left - 1;
    while (!(left < 0 || right >= s.size()) && s[left] == s[right])
    {
        --left;
        ++right;
        pldr += 2;
    }
    return pldr;
}

int solution(string s)
{
    int N = s.size();
    int answer = 1;
   
    /*
        각 문자를 기준으로 팰린드롬이 만들어지는지 확인하고,
        최대길이를 갱신한다.
    */
    for (int i = 0; i < N - 1; ++i)
    {

        // abba 형태 팰린드롬 : 바로 다음문자부터 대칭 시작
        if (i + 1 < N && s[i] == s[i + 1])
        {
            answer = max(get_pldr_len(s, i, i + 1), answer);
        }

        // abcba 형태 팰린드롬 : 문자 하나를 사이에 두고 그다음부터 대칭 시작
        if (i + 2 < N && s[i] == s[i + 2])
        {
            answer = max(get_pldr_len(s, i, i + 2), answer);
        }
    }

    return answer;
}

int main()
{
    /*
    string s = "abcdcba";
    */
    string s = "abacde";

    cout << solution(s);

    return 0;
}