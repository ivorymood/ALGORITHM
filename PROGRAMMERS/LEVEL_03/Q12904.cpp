//https://programmers.co.kr/learn/courses/30/lessons/12904
//���� �� �Ӹ����
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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
        // abba ���� �Ӹ����
        if (i + 1 < N && s[i] == s[i + 1])
        {
            int pldr = 0;
            int l = i;
            int r = i + 1;

            while (!(l < 0 || r >= N) && s[l] == s[r])
            {
                --l;
                ++r;
                pldr += 2;
            }

            answer = max(pldr, answer);
        }
        // abcba ���� �Ӹ����
        if (i + 2 < N && s[i] == s[i + 2])
        {
            int pldr = 1;
            int l = i;
            int r = i + 2;

            while (!(l < 0 || r >= N) && s[l] == s[r])
            {
                --l;
                ++r;
                pldr += 2;
            }

            answer = max(pldr, answer);
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