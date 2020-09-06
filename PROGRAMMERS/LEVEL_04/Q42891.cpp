// https://programmers.co.kr/learn/courses/30/lessons/42891
// 무지의 먹방 라이브
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct food {
    int idx;
    ll time;
};

bool comp_by_time(food &A, food &B)
{
    return A.time < B.time;
}

bool comp_by_idx(food& A, food& B)
{
    return A.idx < B.idx;
}

int solution(vector<int> food_times, long long k) {

    // {인덱스, 시간} 벡터 생성
    vector<food> food_idx_times;
    for (int i = 0; i < food_times.size(); ++i)
    {
        food_idx_times.push_back({ i + 1, food_times[i] });
    }
    
    // 시간을 기준으로 오름차순 정렬
    sort(food_idx_times.begin(), food_idx_times.end(), comp_by_time);
    int size = food_idx_times.size();

    for (int i = 0; i < size; ++i)
    {
        /*
            time_passed_per_round = (현재 최소 음식 시간 * 남은 음식 개수) 
            k = 남은 시간
                        
            이때 food_idx_times벡터는 시간 기준으로 오름차순 정렬되어있으므로
            현재 최소 음식 시간 = time[i] - time[i - 1] 이다.

            한 라운드에 현재 최소 음식 시간을 남은 각각의 음식에서 차감한다.
            k에서는 time_passed_per_round을 차감한다.
        */
        ll bf_time = (i == 0) ? 0 : food_idx_times[i - 1].time;
        ll min_time = food_idx_times[i].time - bf_time;
        ll time_passed_per_round = min_time * (size - i);

        // 남은시간이 차감될 시간보다 더 작을때
        if (time_passed_per_round > k)
        {
            // 인덱스를 기준으로 오름차순 정렬
            sort(food_idx_times.begin() + i, food_idx_times.end(), comp_by_idx);
            
            // 남은 음식 중에서 k번째 음식 인덱스값 반환
            return food_idx_times[k % (size - i) + i].idx;
        }

        k -= time_passed_per_round;
    }

    return -1;
}

int main() {

    /*

    vector<int> food_times = { 3, 1, 2 };
    long long k = 5;
        vector<int> food_times = { 1, 1, 1 };
    long long k = 5;


        vector<int> food_times = { 1, 2, 3, 4 };
    long long k = 8;

    vector<int> food_times = { 1, 1 };
    long long k = 2;
    */

    vector<int> food_times = { 5, 7, 1, 3 };
    long long k = 8;

    cout << solution(food_times, k);

    return 0;
}