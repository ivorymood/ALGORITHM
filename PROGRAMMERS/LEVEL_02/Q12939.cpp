//https://programmers.co.kr/learn/courses/30/lessons/12939
//�ִ񰪰� �ּڰ�
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {

    vector<int> v;

    for (int i = 0; i < s.size(); ++i)
    {
        int end = (s[i] == '-') ? i + 1 : i;
        
        // ���� ��ȯ
        int n = 0;
        while (end < s.size() && s[end] != ' ')
        {
            n *= 10;
            n += s[end] - '0';
            ++end;
        }
        // ���� ��� �ݿ�
        n *= (s[i] == '-') ? -1 : 1;

        // vector push
        v.push_back(n);

        i = end;
    }

    // �ּҰ�, �ִ밪 ���ϱ�
    auto minmax = minmax_element(v.begin(), v.end());

    return to_string(*minmax.first) + " " + to_string(*minmax.second);
}

int main()
{
    /*
    string s = "-1 -1";
    string s = "-1 -2 -3 -4	";
    string s = "1 2 3 4";
    */
    string s = "-192 0 -9 199 32432 -293848";

    cout << solution(s);

    return 0;
}