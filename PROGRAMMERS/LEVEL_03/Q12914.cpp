//https://programmers.co.kr/learn/courses/30/lessons/12914
//멀리 뛰기
#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {

    const long long MOD = 1234567;

    // cnts[i] : i번째 칸에 도달하는 방법의 수
    vector<long long> cnts(n + 1);
    cnts[0] = cnts[1] = 1;

    /*
        i번째 칸까지 오는 방법 
        = (i - 1번째 칸에서 1 더하기) + (i - 2번째 칸에서 2 더하기)

        점화식
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