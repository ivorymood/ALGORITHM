//https://programmers.co.kr/learn/courses/30/lessons/42885
//구명보트
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
   
    // 오름차순 정렬
    sort(people.begin(), people.end());
   
    // 가장 작은 값과 가장 큰 값부터 계산
    int low = 0;
    int high = people.size() - 1;
    int cnt = 0;

    // low와 high가 엇갈리면 종료
    while (low <= high)
    {
        // 큰 값부터 out
        high--;
        cnt++;

        // 작은 값 + 큰 값이 limit 이하이면 작은값도 out
        if (people[low] + people[high] <= limit)
        {
            low++;
        }
    }

    return cnt;
}

int main()
{
    /*
    vector<int> people = { 70, 50, 80, 50 };  int limit = 100;
    vector<int> people = { 60, 50, 70, 50, 40, 100 };  int limit = 100;
    vector<int> people = { 70, 80, 50 };  int limit = 100;
    */
    vector<int> people = { 70 };  int limit = 100;

    cout << solution(people, limit);

    return 0;
}