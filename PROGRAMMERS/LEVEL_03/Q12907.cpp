//https://programmers.co.kr/learn/courses/30/lessons/12907
//거스름돈
#include <iostream>

#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> coins) {

    // 동전으로 N원을 만드는 방법의 수
    vector<int> ways(n + 1);

    // 0원을 만드는 방법의 수 : 1 (아무동전도 사용하지 않는 것)
    ways[0] = 1;

    // [N]원을 만드는 방법의 수 += [N - x]원을 만드는 방법의 수 (x = 코인)
    for (int coin : coins)
    {
        for (int i = coin; i <= n; ++i)
        {
            ways[i] += ways[i - coin];
            ways[i] %= MOD;
        }
    }
    
    return ways[n];
}

int main()
{
    int n = 5;  vector<int> money = { 1, 2, 5 };

    cout << solution(n, money);

    return 0;
}