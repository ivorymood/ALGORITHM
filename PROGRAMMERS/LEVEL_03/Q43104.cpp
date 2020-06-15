//https://programmers.co.kr/learn/courses/30/lessons/43104
//타일 장식물
#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long solution1(int N) {

    /*
        타일 한변의 길이는 피보나치 수열로 증가

        N번째 사각형이 더해진 전체 직사각형의 두 변 :
        - dp[N]
        - dp[N + 1] (= dp[N] + dp[N - 1])
    */
    vector<long long> tile(N + 2);
    
    tile[1] = tile[2] = 1;
    for (int i = 3; i <= N + 1; ++i)
    {
        tile[i] = tile[i - 1] + tile[i - 2];
    }

    return (tile[N] + tile[N + 1]) * 2;
}

long long solution2(int N) {

    /*
        타일 한변의 길이는 피보나치 수열로 증가

        N번째 사각형이 더해진 전체 직사각형의 두 변 :
        - x : 이전의 y 값
        - y : x가 더해진 값
    */
    int x = 1, y = 1;
    for (int i = 0; i < N - 1; ++i)
    {
        int tmp = y;
        y += x;
        x = tmp;
    }

    return (x + y) * 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    int N = 5;
    */
    int N = 6;

    cout << solution2(N);

    return 0;
}