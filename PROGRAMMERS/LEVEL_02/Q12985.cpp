//https://programmers.co.kr/learn/courses/30/lessons/12985
//예상 대진표
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt = 0;
    // a = b가 되면 종료
    while (a != b)
    {
        // a와 b가 같지 않으면 대진
        ++cnt;

        // a 와 b의 다음 대진표 번호 구하기
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