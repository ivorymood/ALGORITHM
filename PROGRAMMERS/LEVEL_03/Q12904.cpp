//https://programmers.co.kr/learn/courses/30/lessons/12904
//���� �� �Ӹ����
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
        �� ���ڸ� �������� �Ӹ������ ����������� Ȯ���ϰ�,
        �ִ���̸� �����Ѵ�.
    */
    for (int i = 0; i < N - 1; ++i)
    {

        // abba ���� �Ӹ���� : �ٷ� �������ں��� ��Ī ����
        if (i + 1 < N && s[i] == s[i + 1])
        {
            answer = max(get_pldr_len(s, i, i + 1), answer);
        }

        // abcba ���� �Ӹ���� : ���� �ϳ��� ���̿� �ΰ� �״������� ��Ī ����
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