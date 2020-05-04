//https://programmers.co.kr/learn/courses/30/lessons/42586
//기능개발 

#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
   
    int day;            // 작업 완료에 걸리는 시간
    int max_day = 0;    // 배포될때까지 기다려야 하는 시간

    // 앞에서부터 순차적으로 배포개수 카운팅
    for (int i = 0; i < progresses.size(); i++)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        // 해당 기능의 작업시간이 이전 기능보다 더 오래걸릴 때
        if (day > max_day)
        {
            answer.push_back(1);
            max_day = day;
        }
        // 그렇지 않고, 이전 기능이 완료될 때까지 기다려야 할때
        else
        {
            answer.back()++;
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