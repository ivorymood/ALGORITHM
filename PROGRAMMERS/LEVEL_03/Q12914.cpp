//https://programmers.co.kr/learn/courses/30/lessons/12914
//�ָ� �ٱ�
#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {

    const long long MOD = 1234567;

    // cnts[i] : i��° ĭ�� �����ϴ� ����� ��
    vector<long long> cnts(n + 1);
    cnts[0] = cnts[1] = 1;

    /*
        i��° ĭ���� ���� ��� 
        = (i - 1��° ĭ���� 1 ���ϱ�) + (i - 2��° ĭ���� 2 ���ϱ�)

        ��ȭ��
        : cnts[i] = cnts[i - 1] + cnts[i - 2];
    */
    for (int i = 2; i <= n; ++i)
    {
        cnts[i] = (cnts[i - 1] + cnts[i - 2]) % MOD;
    }

    return cnts[n];
}

int main()
{
    /*
    int n = 4;
    */
    int n = 3;

    cout << solution(n);

    return 0;
}