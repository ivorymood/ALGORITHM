//https://programmers.co.kr/learn/courses/30/lessons/12985
//���� ����ǥ
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 0;
    // a = b�� �Ǹ� ����
    while (a != b)
    {
        // a�� b�� ���� ������ ����
        ++cnt;

        // a �� b�� ���� ����ǥ ��ȣ ���ϱ�
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }

    return cnt;
}

int main()
{

    int n = 8; int a = 4; int b = 7;

    cout << solution(n, a, b);

    return 0;
}