//https://programmers.co.kr/learn/courses/30/lessons/43238
//입국심사
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

// t시간 내에 목표한 사람수를 모두 심사할 수 있으면 true 반환
bool possible(vector<int>& times, ll t, int target)
{
    ll passed = 0;
    for (int i = 0; i < times.size(); ++i)
    {
        passed += t / times[i];
    }
    return (passed >= target);
}

ll search(vector<int>& times, ll start, ll end, ll target, ll answer)
{
    // 왼쪽 끝값 > 오른쪽 끝값 일 때, 오른쪽 끝값 반환
    if (start > end)
    {
        return answer;
    }

    // mid값이 충분하면 (=mid시간 내에 주어진 사람수를 모두 심사할 수 있으면)
    // : 오른쪽 끝값을 중간값 - 1로 search 재귀함수 호출
    ll mid = (start + end) / 2;
    if (possible(times, mid, target))
    {
        answer = min(mid, answer);
        return search(times, start, mid - 1, target, answer);
    }
    // mid값이 너무 작으면 : 왼쪽 끝값을 중간값 + 1로 search 재귀함수 호출
    else
    {
        return search(times, mid + 1, end, target, answer);
    }
}

ll solution(int n, vector<int> times) {

    // 오름차순 정렬
    sort(times.begin(), times.end());

    // 주어진 사람 수 n을 전부 심사하는 데에 최소, 최대로 걸리는 시간
    ll low = ((ll)n * times.front()) / times.size();
    ll high = (ll)n * (ll)times.back();

    /*
        이분탐색으로 모든 사람이 심사를 받을 수 있는
        가능한 최소의 시간 구하기
    */
    return search(times, low, high, n, numeric_limits<ll>::max());
}

int main()
{
    int n = 1000000000; vector<int> times = { 1, 1000000000, 1000000000 }; //1000000000
    /*
    int n = 6; vector<int> times = {8, 10}; // 30
    int n = 6; vector<int> times = {7, 10}; // 28
    int n = 6; vector<int> times = {6, 10}; // 24
    int n = 6; vector<int> times = {4, 10}; // 20
    int n = 11; vector<int> times = {3, 4, 10}; // 18
    int n = 5; vector<int> times = {3, 5, 7};
    int n = 1000000005; vector<int> times = { 1, 1000000000, 1000000000 }; //1000000000
    */

    cout << solution(n, times);

    return 0;
}