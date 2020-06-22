//https://programmers.co.kr/learn/courses/30/lessons/12900
//2 x n 타일링
#include <iostream>

#include <string>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
const int MAX = 60000;
long long D[MAX + 1];

int solution(int n) {

    D[0] = 1;
    D[1] = 1;

    // 점화식 : D[n] = D[n - 1] + D[n - 2
    for (int i = 2; i <= n; ++i)
    {
        D[i] = (D[i - 1] + D[i - 2]) % MOD;
    }

    return D[n];
}

int main()
{
    int n = 4;
    cout << solution(n);

    return 0;
}