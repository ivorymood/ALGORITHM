//https://programmers.co.kr/learn/courses/30/lessons/64062
//징검다리 건너기
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200000000;

bool check(vector<int> &stones, int k, int passed)
{
    // 왼쪽 땅부터 시작
    int last_idx = -1;
    for (int i = 0; i < stones.size(); ++i)
    {
        // 건널 수 있는 디딤돌이면
        if (stones[i] - passed >= 0)
        {
            // 마지막 디딤돌간의 간격이 k초과이면 false
            if (i - last_idx > k)
            {
                return false;
            }
            last_idx = i;
        }
    }

    // 오른쪽 땅까지의 거리가 k이하면 true
    return (stones.size() - last_idx <= k);
}

int solution(vector<int> stones, int k) {

    // stones 요소 중 최소값/최대값 구하기
    int left = MAX;
    int right = 0;
    for (int stone : stones)
    {
        left = min(stone, left);
        right = max(stone, right);
    }

    /*
        이분탐색
        조건을 만족하는 디딤돌 숫자 중 최대값 구하기
    */
    int answer = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(stones, k, mid))
        {
            answer = max(mid, answer);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }; int k = 3;

    cout << solution(stones, k);

    return 0;
}