//https://programmers.co.kr/learn/courses/30/lessons/12977
//소수 만들기
#include <iostream>
#include <vector>
using namespace std;

int cnt;

// 소수 판별
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(vector<int> &nums, int sum, int N, int depth, int start)
{
    // N개의 숫자를 고르면 sum이 소수인지 판별하고 카운트
    if (depth == N)
    {
        if (is_prime(sum))
        {
            ++cnt;
        }
        return;
    }

    // 서로 다른 N개의 숫자를 구해야하므로,
    // 이전 depth의 다음 자리 숫자부터 for문 돌리기
    for (int i = start; i < nums.size(); ++i)
    {
        dfs(nums, sum + nums[i], N, depth + 1, i + 1);
    }
}

int solution(vector<int> nums) {
    
    const int pick = 3;
    dfs(nums, 0, pick, 0, 0);

    return cnt;
}

int main()
{
    /*
    vector<int> nums = { 1,2,3,4 };
    */
    vector<int> nums = { 1,2,7,6,4 };

    cout << solution(nums);

    return 0;
}