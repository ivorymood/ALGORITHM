//https://programmers.co.kr/learn/courses/30/lessons/12980
//������ ���� �̵�
#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int cnt = 0;
    
    // n�������� 0���� ���� ���
    while (n > 0)
    {
        // n�� Ȧ���� 1ĭ ����
        if (n % 2)
        {
            ++cnt;
        }
        /*
           n�� Ȧ¦ ���ο� ������� ������ n�� 2�� ������.
           ������ n�� Ȧ���� ���� �߿��ϱ� ����.
        */
        n /= 2;
    }

    return cnt;
}

int main()
{
    /*
    int n = 5000;
    int n = 6;
    */
    int n = 5;

    cout << solution(n);

    return 0;
}