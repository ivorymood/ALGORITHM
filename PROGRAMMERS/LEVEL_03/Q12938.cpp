//https://programmers.co.kr/learn/courses/30/lessons/12938
//�ְ��� ����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {

    // n���� �ڿ����� s�� ���� �� ���� ���
    if (n > s)
    {
        return { -1 };
    }
    
    // �ʱ⿡ n���� �ڿ����� ���� (s / n)�� ���� ����
    int qe = s / n;
    vector<int> answer(n, qe);

    // s���� (int)(s / n) * n��ŭ�� ���ϱ�
    s -= n * qe;
    
    // �ڿ������� ���� ���ڵ��� 1�� ������
    for (int i = n - 1; i >= 0; --i)
    {
        ++answer[i];
        --s;
        if (s == 0)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    /*
    int n = 2; int s = 1;
    int n = 2; int s = 8;
    */
    int n = 2; int s = 9;

    vector<int> res = solution(n, s);

    for (int i : res)
    {
        cout << i << ' ';
    }

    return 0;
}