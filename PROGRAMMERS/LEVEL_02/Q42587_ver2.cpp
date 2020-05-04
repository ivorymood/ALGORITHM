//https://programmers.co.kr/learn/courses/30/lessons/42587
//프린터 
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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
        int now = q.front();

        // 현재 front 인덱스의 값이 가장 큰 우선순위라면
        if (priorities[now] == *max_element(priorities.begin(), priorities.end()))
        {
            order[now] = ordering++;
            q.pop();
            
            // 우선순위에서 해당 인덱스의 우선순위값 -1처리
            priorities[now] = -1;
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