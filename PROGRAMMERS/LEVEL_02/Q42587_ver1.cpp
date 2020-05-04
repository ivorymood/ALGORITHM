//https://programmers.co.kr/learn/courses/30/lessons/42587
//프린터
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    vector<int> order(priorities.size());
    queue<int> q;
    int ordering = 0;

    // 먼저 queue에 모든 인덱스 push
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        // 전체에서 우선순위가 가장 높은 값을 가진 인덱스 찾기
        // front를 계속해서 queue의 맨 뒤로 보내면서 순회
        int now = q.front();
        q.push(now);
        q.pop();

        int max = now;
        while (now != q.front())
        {
            if (priorities[max] < priorities[q.front()])
            {
                max = q.front();
            }
            q.push(q.front());
            q.pop();
        }

        // 현재 front에 있는 인덱스 값이 우선순위가 가장 높다면
        // order벡터에 출력순서 입력
        if (max == now)
        {
            order[now] = ordering++;
            q.pop();
        }
        // 아니라면 queue의 맨 뒤로
        else
        {
            q.push(now);
            q.pop();
        }
    }

    // 원하는 인덱스의 출력순서 return
    return order[location] + 1;
}

int main()
{
    /*
    vector<int> priorities = { 2, 1, 3, 2 };
    int location = 2;
    vector<int> priorities = { 1, 2, 3, 4 };
    int location = 2;
    vector<int> priorities = { 1 , 1, 1};
    int location = 2;
    */
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;
    cout << solution(priorities, location);

    return 0;
}