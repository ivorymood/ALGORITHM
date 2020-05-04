//https://programmers.co.kr/learn/courses/30/lessons/12899
//124 ������ ���� 
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 3���� �� ���ϱ�
string get_ternary(int n)
{
    if (n == 0)
    {
        return "";
    }

    return get_ternary(n / 3).append(to_string(n % 3));
}

string solution(int n) {

    string tri = get_ternary(n);

    // �ڿ������� 0�̸� ��ü�� - 1 �� ��, 0 --> 4�� ��ȯ
    for (int i = tri.size() - 1; i > 0; i--)
    {
        if (tri[i] == '0')
        {
            tri[i - 1] -= 1;
            tri[i] = '4';
        }
        else if (tri[i] < '0')
        {
            tri[i - 1] -= 1;
            tri[i] += 3;
        }
    }

    if (tri[0] == '0')
    {
        return tri.substr(1);
    }

    return tri;
}

int main()
{
    int n;
    cin >> n;

    cout << solution(n);
    return 0;
}