//https://programmers.co.kr/learn/courses/30/lessons/12927
//야근 지수
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {

    // 우선 순위 큐에 works 요소 복사
    priority_queue<int, vector<int>, less<int>> pq;
    int sum = 0;
    for (int i : works)
    {
        pq.push(i);
        sum += i;
    }

    // 전체 남은 작업량보다 n이 같거나 크다면 0 반환
    if (sum <= n)
    {
        return 0;
    }

    // n시간 동안 가장 큰 작업물을 1씩 처리
    while (n--)
    {
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp - 1);
    }

    // 야근 피로도 계산
    long long answer = 0;
    while (!pq.empty())
    {
        answer += (long long)pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{
    /*
    int n = 4; vector<int> works = { 4, 3, 3 };
    int n = 1; vector<int> works = { 2, 1, 2 };
    */
    int n = 3; vector<int> works = { 1,1 };

    cout << solution(n, works);

    return 0;
}