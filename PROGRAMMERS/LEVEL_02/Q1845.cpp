//https://programmers.co.kr/learn/courses/30/lessons/1845
//폰켓몬
#include <iostream>

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    // nums -> set으로 변환
    unordered_set<int> set(nums.begin(), nums.end());

    // 폰켓몬의 종류 수와 N / 2 중 더 작은 값을 반환
    return min(set.size(), nums.size() / 2);
}

int main()
{
    /*
    vector<int> nums = { 3,3,3,2,2,4 };
    vector<int> nums = { 3,3,3,2,2,2 };
    */
    vector<int> nums = { 3,1,2,3 };

    cout << solution(nums);

    return 0;
}