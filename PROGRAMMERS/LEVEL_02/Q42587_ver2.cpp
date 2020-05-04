//https://programmers.co.kr/learn/courses/30/lessons/42587
//������ 
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

    // ���� queue�� ��� �ε��� push
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int now = q.front();

        // ���� front �ε����� ���� ���� ū �켱�������
        if (priorities[now] == *max_element(priorities.begin(), priorities.end()))
        {
            order[now] = ordering++;
            q.pop();
            
            // �켱�������� �ش� �ε����� �켱������ -1ó��
            priorities[now] = -1;
        }
        // �ƴ϶�� queue�� �� �ڷ�
        else
        {
            q.push(now);
            q.pop();
        }
    }

    // ���ϴ� �ε����� ��¼��� return
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