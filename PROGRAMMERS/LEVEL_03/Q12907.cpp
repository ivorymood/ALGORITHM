//https://programmers.co.kr/learn/courses/30/lessons/12907
//�Ž�����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> coins) {

    // �������� N���� ����� ����� ��
    vector<int> ways(n + 1);

    // 0���� ����� ����� �� : 1 (�ƹ������� ������� �ʴ� ��)
    ways[0] = 1;

    // [N]���� ����� ����� �� += [N - x]���� ����� ����� �� (x = ����)
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