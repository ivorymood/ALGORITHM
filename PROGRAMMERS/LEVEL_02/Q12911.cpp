//https://programmers.co.kr/learn/courses/30/lessons/12911
//다음 큰 숫자
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
        // 2^i의 자리에 1이 있을때
        if (n & 0x01 << i)
        {
            ++cnt;
        }
    }
    return cnt;
}

int solution(int n) {
    
    // input값이 2진수일때 1의 개수 구하기
    int cnt = get_1_count(n);
    int answer = n + 1;

    // 다음 큰 숫자가 input값과 1의 개수가 같을 때까지 증가 시키기 
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