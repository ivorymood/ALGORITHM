//https://programmers.co.kr/learn/courses/30/lessons/42586
//��ɰ���

#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    // queue�� ��� �ε��� �ֱ�
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++)
    {
        q.push(i);
    }
    
    vector<int> answer;
    int tobe = 0;
    while (!q.empty())
    {
        // ���� �����ȵ� ��ɺ��� �۾� ����
        for (int i = tobe; i < progresses.size(); i++)
        {
            if (progresses[i] < 100)
            {
                progresses[i] += speeds[i];
            }
        }

        // ���� �������� �۾��� �Ϸ� �Ǹ�
        if (progresses[tobe] >= 100)
        {
            // �Ϸ� ������ �۾��� ��� ���� & ī����
            int cnt = 0;
            while (!q.empty() && progresses[q.front()] >= 100)
            {
                q.pop();
                cnt++;
            }
            tobe += cnt;
            answer.push_back(cnt);
        }
    }
    
    return answer;
}

int main()
{
    vector<int> progresses = { 93,30,55 };
    vector<int> speeds = { 1,30,5 };

    vector<int> rtn = solution(progresses, speeds);
    for (int i = 0; i < rtn.size(); i++)
    {
        cout << rtn[i] << ", ";
    }

    return 0;
}