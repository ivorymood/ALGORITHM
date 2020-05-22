//https://programmers.co.kr/learn/courses/30/lessons/12980
//점프와 순간 이동
#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int cnt = 0;
    
    // n에서부터 0까지 가는 방법
    while (n > 0)
    {
        // n이 홀수면 1칸 점프
        if (n % 2)
        {
            ++cnt;
        }
        /*
           n의 홀짝 여부와 상관없이 무조건 n은 2로 나눈다.
           다음번 n이 홀수일 때만 중요하기 때문.
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