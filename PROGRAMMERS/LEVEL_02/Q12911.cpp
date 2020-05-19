//https://programmers.co.kr/learn/courses/30/lessons/12911
//���� ū ����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int get_1_count(int n)
{
    int cnt = 0;
    while (n)
    {
        if (n % 2 == 1)
        {
            ++cnt;
        }
        n /= 2;
    }
    return cnt;
}

int get_1_count_bit_ver(int n)
{
    int cnt = 0;
    for (int i = 0; i < 31; ++i)
    {
        // 2^i�� �ڸ��� 1�� ������
        if (n & 0x01 << i)
        {
            ++cnt;
        }
    }
    return cnt;
}

int solution(int n) {
    
    // input���� 2�����϶� 1�� ���� ���ϱ�
    int cnt = get_1_count(n);
    int answer = n + 1;

    // ���� ū ���ڰ� input���� 1�� ������ ���� ������ ���� ��Ű�� 
    while (get_1_count(answer) != cnt)
    {
        ++answer;
    }
    return answer;
}

int main()
{
    /*
    int n = 78;
    */
    int n = 15;

    cout << solution(n);

    return 0;
}