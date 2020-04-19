//https://www.acmicpc.net/problem/16194
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int cost[MAX + 1];
int min_cost[MAX + 1];

// 점화식 : D[n] = min(D[n - i] + P[i])
int get_min_cost(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (min_cost[n] > 0)
    {
        return min_cost[n];
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = get_min_cost(n - i) + cost[i];
        // 문제에서 카드값은 1 ≤ Pi ≤ 10,000 이므로, 
        // (min_cost == 0) 여부를 기준으로 구분해도 상관없다
        min_cost[n] = (min_cost[n] < 0) ? temp : min(min_cost[n], temp);
    }

    return min_cost[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        // 값을 아직 구하지 않았다는 뜻
        min_cost[i] = -1;
    }

    get_min_cost(n);

    cout << min_cost[n];

    return 0;
}
