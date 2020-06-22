//https://programmers.co.kr/learn/courses/30/lessons/43237
//예산
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_limited_sum(vector<int> &budgets, int limit)
{
    int sum = 0;
    for (auto iter = budgets.begin(); iter != budgets.end(); ++iter)
    {
        // 요청액이 limit보다 크면 sum에 limit값을 대신 더해주기
        if (*iter > limit)
        {
            sum += limit;
        }
        else 
        {
            sum += *iter;
        }
    }
    return sum;
}

int search(vector<int> &budgets, int start, int end, int target)
{
    // 왼쪽 끝값 > 오른쪽 끝값 일 때, 오른쪽 끝값 반환
    if (start > end)
    {
        return end;
    }

    // 중간값을 limit으로 했을 때 총 요청합 구하기
    int mid = (start + end) / 2;
    int sum = get_limited_sum(budgets, mid);

    // 요청합 == 목표 예산합 : limit값 반환
    if (sum == target)
    {
        return mid;
    }
    // limit이 너무 큰 경우 : 오른쪽 끝값을 중간값 -1로 search 재귀함수 호출
    else if (sum > target)
    {
        return search(budgets, start, mid - 1, target);
    }
    // limit이 너무 작은 경우 : 왼쪽 끝값을 중간값 +1로 search 재귀함수 호출
    else 
    {
        return search(budgets, mid + 1, end, target);
    }
}

int solution(vector<int> budgets, int M) {

    // 이분탐색 최소, 최대 시작값을 정하기 위해 오름차순 정렬
    sort(budgets.begin(), budgets.end());

    /*
        모든 요청이 배정될 수 없는 경우도 있을 수 있으므로
        (총 예산 / 지방 개수)와 최소 예산 요청액을 비교해서 
        더 작은 값으로 이분탐색을 시작한다.
    */
    int len = budgets.size();
    int min_start = min(budgets.front(), M / len);

    return search(budgets, min_start, budgets.back(), M);
}

int main()
{
    /*
    vector<int> budgets = { 120, 110, 140, 150 }; int M = 485;
    
    */
    vector<int> budgets = {5, 6, 7, 8, 9}; int M = 5;

    cout << solution(budgets, M);

    return 0;
}