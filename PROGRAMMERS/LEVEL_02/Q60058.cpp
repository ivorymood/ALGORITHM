//https://programmers.co.kr/learn/courses/30/lessons/60058
//��ȣ ��ȯ
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// ���ڿ��� �յڸ� �ڸ��� ��ȣ ����
string make_reverse_except_ft(const string &u)
{
    string tmp = u.substr(1, u.size() - 2);

    for (char &c : tmp)
    {
        c = ((c == '(') ? ')' : '(');
    }
    return tmp;
}

// Ʋ�� ���ڿ� ���� �ε��� ��ȯ
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

// �ùٸ� ��ȣ ���ڿ� ���� üũ
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
    // �� ���ڿ��� �־����� ��
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

    // �ùٸ� ���ڿ� or �� ���ڿ��� �־����� ��� : �Է� ���ڿ� �״�� ��ȯ
    if (make_balanced_string(s, u, v) == false || is_right_string(s))
    {
        return s;
    }

    // u�� �ùٸ� ���ڿ�O : u + v��� ȣ�� ��� ��ȯ
    if (is_right_string(u))
    {
        return u + make_right_string(v);
    }

    // u�� �ùٸ� ���ڿ�X : ( + v��� ȣ�� ��� + ) + u�� �յڸ� �ڸ��� ��ȣ ������ ��� ��ȯ
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