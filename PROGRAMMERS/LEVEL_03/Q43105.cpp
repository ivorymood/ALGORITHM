//https://programmers.co.kr/learn/courses/30/lessons/43105
//정수 삼각형
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 500;
int D[MAX + 1][MAX + 1];

int solution(vector<vector<int>> triangle) {

    int N = triangle.size();
    
    /*
           점화식 :
           D[i][j] = tri[i][j]로 올 수 있는 경로의 i - 1번째 최대값
                   + tri[i][j]
    */
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + triangle[i - 1][j - 1];
        }
    }

    // 최대값 구하기
    int max_sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        max_sum = max(D[N][i] , max_sum);
    }

    return max_sum;
}

int main()
{
    vector<vector<int>> triangle = { {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };

    cout << solution(triangle);

    return 0;
}