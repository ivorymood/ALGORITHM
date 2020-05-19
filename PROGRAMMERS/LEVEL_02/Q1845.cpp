//https://programmers.co.kr/learn/courses/30/lessons/1845
//���ϸ�
#include <iostream>

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    // nums -> set���� ��ȯ
    unordered_set<int> set(nums.begin(), nums.end());

    // ���ϸ��� ���� ���� N / 2 �� �� ���� ���� ��ȯ
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