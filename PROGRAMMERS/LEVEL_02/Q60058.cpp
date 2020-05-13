//https://programmers.co.kr/learn/courses/30/lessons/60058
//괄호 변환
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 문자열의 앞뒤를 자르고 괄호 반전
string make_reverse_except_ft(const string &u)
{
    string tmp = u.substr(1, u.size() - 2);

    for (char &c : tmp)
    {
        c = ((c == '(') ? ')' : '(');
    }
    return tmp;
}

// 틀린 문자열 시작 인덱스 반환
int get_wrong_string_start(const string &s)
{
    int cnt = 0;
    int balanced = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            ++cnt;
        else
            --cnt;

        if (cnt == 0)
        {
            balanced = i;
            break;
        }
    }
    return balanced + 1;
}

// 올바른 괄호 문자열 여부 체크
bool is_right_string(const string& s)
{
    int cnt = 0;
    for (const char &c : s)
    {
        if (c == '(')
            ++cnt;
        else
            --cnt;

        if (cnt < 0)
            return false;
    }
    return (cnt > 0) ? false : true;
}

bool make_balanced_string(const string& s, string& u, string& v)
{
    // 빈 문자열이 주어졌을 때
    if (s.size() == 0)
    {
        return false;
    }

    int v_strt = get_wrong_string_start(s);
    u = s.substr(0, v_strt);
    v = s.substr(v_strt);

    return true;
}

string make_right_string(const string &s)
{
    string u = "";
    string v = "";

    // 올바른 문자열 or 빈 문자열이 주어졌을 경우 : 입력 문자열 그대로 반환
    if (make_balanced_string(s, u, v) == false || is_right_string(s))
    {
        return s;
    }

    // u가 올바른 문자열O : u + v재귀 호출 결과 반환
    if (is_right_string(u))
    {
        return u + make_right_string(v);
    }

    // u가 올바른 문자열X : ( + v재귀 호출 결과 + ) + u의 앞뒤를 자르고 괄호 반전한 결과 반환
    return '(' + make_right_string(v) + ')' + make_reverse_except_ft(u);
}

string solution(string p) {

    return make_right_string(p);
}

int main()
{
    /*
    string p = ")(";
    string p = "(()())()";
    */
    string p = "()))((()";

    cout << solution(p);

    return 0;
}