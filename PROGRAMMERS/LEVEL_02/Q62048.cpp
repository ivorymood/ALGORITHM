//https://programmers.co.kr/learn/courses/30/lessons/62048
//멀쩡한 사각형
#include <iostream>

using namespace std;

/*
    unit : 가로 세로를 최대공약수로 나눈 수로 이루어진 사각형

    대각선이 지나가는 전체 사각형의 수 
    = 한 unit에서 대각선이 지나가는 사각형의 수 * gcd 
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

    // 전체 사각형 개수 - 대각선이 지나가는 사각형 개수
    return answer - (long long)cut_cnt_per_unit * gcd;
}

int main()
{
    int w = 8; int h = 12;
    cout << solution(w, h);

    return 0;
}