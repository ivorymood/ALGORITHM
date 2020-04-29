//https://programmers.co.kr/learn/courses/30/lessons/42586
//기능개발

#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    // queue에 모든 인덱스 넣기
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++)
    {
        q.push(i);
    }
    
    vector<int> answer;
    int tobe = 0;
    while (!q.empty())
    {
        // 아직 배포안된 기능부터 작업 진행
        for (int i = tobe; i < progresses.size(); i++)
        {
            if (progresses[i] < 100)
            {
                progresses[i] += speeds[i];
            }
        }

        // 배포 다음순서 작업이 완료 되면
        if (progresses[tobe] >= 100)
        {
            // 완료 상태인 작업물 모두 배포 & 카운팅
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