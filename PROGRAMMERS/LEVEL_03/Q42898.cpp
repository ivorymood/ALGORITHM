//https://programmers.co.kr/learn/courses/30/lessons/42898
//���
#include <iostream>

#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    // �������� m : ��, n : ���� �־�����.
    vector<vector<int>> ways(m + 1, vector<int>(n + 1));
    vector<vector<bool>> is_puddle(m + 1, vector<bool>(n + 1));

    // �� ������ üũ : puddle�迭�� <��, ��>���� �־����Ƿ� �ݴ�� 
    for (int i = 0; i < puddles.size(); ++i)
    {
        is_puddle[puddles[i][1]][puddles[i][0]] = true;
    }

    // DP
    ways[0][1] = 1;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // �� �����̰� �ƴ� ��
            if (!is_puddle[i][j])
            {
                /*
                    �� ������ �ִܰŸ��� �����ϴ� ����� �� 
                    : ��ĭ���� ���� ����� �� + ����ĭ���� ���� ����� ��
                */
                ways[i][j] = (ways[i - 1][j] + ways[i][j - 1]) % MOD;
            }
        }
    }

    return ways[m][n];
}

int main()
{
    int m = 4; int n = 3; vector<vector<int>> puddles = { {2, 3} };
    
    cout << solution(m, n, puddles);

    return 0;
}