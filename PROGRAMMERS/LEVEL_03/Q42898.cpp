//https://programmers.co.kr/learn/courses/30/lessons/42898
//등굣길
#include <iostream>

#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    // 문제에서 m : 행, n : 열로 주어진다.
    vector<vector<int>> ways(m + 1, vector<int>(n + 1));
    vector<vector<bool>> is_puddle(m + 1, vector<bool>(n + 1));

    // 물 웅덩이 체크 : puddle배열이 <열, 행>으로 주어지므로 반대로 
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
            // 물 웅덩이가 아닐 때
            if (!is_puddle[i][j])
            {
                /*
                    한 지점에 최단거리로 도착하는 경우의 수 
                    : 위칸까지 오는 방법의 수 + 왼쪽칸까지 오는 방법의 수
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