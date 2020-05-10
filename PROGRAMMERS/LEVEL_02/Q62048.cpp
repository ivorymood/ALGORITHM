//https://programmers.co.kr/learn/courses/30/lessons/62048
//������ �簢��
#include <iostream>

using namespace std;

/*
    unit : ���� ���θ� �ִ������� ���� ���� �̷���� �簢��

    �밢���� �������� ��ü �簢���� �� 
    = �� unit���� �밢���� �������� �簢���� �� * gcd 
*/
int inline get_cut_cnt_per_unit(int w, int h)
{
    return w + h - 1;
}

int GCD(int A, int B)
{
    if (B == 0)
    {
        return A;
    }

    return GCD(B, A % B);
}

long long solution(int w, int h) {

    long long answer = (long long)w * h;

    int gcd = GCD(w, h);
    
    int cut_cnt_per_unit = get_cut_cnt_per_unit(w / gcd, h / gcd);

    // ��ü �簢�� ���� - �밢���� �������� �簢�� ����
    return answer - (long long)cut_cnt_per_unit * gcd;
}

int main()
{
    int w = 8; int h = 12;
    cout << solution(w, h);

    return 0;
}