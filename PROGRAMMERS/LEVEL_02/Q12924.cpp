//https://programmers.co.kr/learn/courses/30/lessons/12924
//������ ǥ��
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    // i���� ���ӵ� �ڿ����� ���� n�̸� ī��Ʈ
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = i; j <= n; ++j)
        {
            sum += j;
            if (sum >= n)
            {
                cnt += (sum == n) ? 1 : 0;
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int n = 15;
    cout << solution(n);

    return 0;
}