//https://programmers.co.kr/learn/courses/30/lessons/12913
//땅따먹기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_ROW = 100000;
const int MAX_COLUMN = 4;
int dp[MAX_ROW + 1][MAX_COLUMN];

// 주어진 배열에서 한 인덱스를 제외하고 나머지 값 중 최대값 구하기
int get_max_except(const int row[], const int except)
{
    int max = 0;
    for (int i = 0; i < MAX_COLUMN; ++i)
    {
        if (i != except && max < row[i])
        {
            max = row[i];
        }
    }
    return max;
}

int solution(vector<vector<int>> land)
{
    /*
        점화식
        dp[i][j] : land[i][j]를 포함하는 경우의 최대값

        --> dp[i][j] = max(dp[i - 1][j 제외]) + land[i][j]
    */
    int length = land.size();
    for (int i = 1; i <= length; ++i)
    {
        for (int j = 0; j < MAX_COLUMN; ++j)
        {
            dp[i][j] = get_max_except(dp[i - 1], j) + land[i - 1][j];
        }
    }

    // dp배열의 마지막 행에서 최대값 반환
    return *max_element(dp[length], dp[length] + MAX_COLUMN);
}

int main()
{
    vector<vector<int>> land{{1, 2, 3, 5},{5, 6, 7, 8},{4, 3, 2, 1}};

    cout << solution(land);

    return 0;
}