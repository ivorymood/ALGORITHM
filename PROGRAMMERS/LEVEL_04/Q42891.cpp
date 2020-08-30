//https://programmers.co.kr/learn/courses/30/lessons/42891
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

    vector<food> food_idx_times;
    for (int i = 0; i < food_times.size(); ++i)
    {
        food_idx_times.push_back({ i + 1, food_times[i] });
    }
    
    int size = food_idx_times.size();
    sort(food_idx_times.begin(), food_idx_times.end(), comp_by_time);

    for (int i = 0; i < size; ++i)
    {
        ll bf_time = (i == 0) ? 0 : food_idx_times[i - 1].time;
        ll min_time = food_idx_times[i].time - bf_time;
        ll time_passed_per_round = min_time * (size - i);

        if (time_passed_per_round > k)
        {
            sort(food_idx_times.begin() + i, food_idx_times.end(), comp_by_idx);
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