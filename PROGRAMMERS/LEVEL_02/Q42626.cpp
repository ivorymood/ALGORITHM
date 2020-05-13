//https://programmers.co.kr/learn/courses/30/lessons/42626
//더 맵게
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {

    // 최소 힙에 scoville 요소 담기 
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    // 힙의 최소값이 K 이상이 되면, 섞은 횟수 반환
    int answer = 0;
    while (!pq.empty() && pq.top() < K)
    {
        // 남은 힙의 요소가 1개이고, 요소 값이 K 미만 일때 : 불가능
        if (pq.size() == 1)
        {
            return -1;
        }

        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        pq.push(min1 + min2 * 2);
        ++answer;

    }

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 }; int K = 7;

    cout << solution(scoville, K);

    return 0;
}