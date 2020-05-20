//https://programmers.co.kr/learn/courses/30/lessons/12924
//숫자의 표현
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    // i부터 연속된 자연수의 합이 n이면 카운트
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