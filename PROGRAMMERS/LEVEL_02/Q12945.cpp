//https://programmers.co.kr/learn/courses/30/lessons/12945
//피보나치 수
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    const int MOV = 1234567;
    const int MAX = 100000;
    int fibo[MAX + 1] = { 0, };

    fibo[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOV;
    }

    return fibo[n];
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n);

    return 0;
}