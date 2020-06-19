//https://programmers.co.kr/learn/courses/30/lessons/42627
//디스크 컨트롤러
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct work {
    int in, w_time;
};

bool my_compare(work& a, work& b)
{
    return a.w_time > b.w_time;
}

int solution(vector<vector<int>> jobs) {

    // 요청시각 오름차순으로 정렬
    sort(jobs.begin(), jobs.end());

    // 작업을 작업시간 오름차순으로 정렬하는 우선순위 큐
    //priority_queue<work, vector<work>, compare> q;
    priority_queue<work, vector<work>, decltype(&my_compare)> q(my_compare);

    int N = jobs.size();
    int now = 0, cnt = 0, t_stay = 0, done = 0;

    // 모든 작업을 마칠 때까지 반복문
    while (N - done)
    {
        // 아직 추가하지 않은 작업물 부터 반복문
        for (int i = cnt; i < N; ++i)
        {
            // 현재 이전에 요청받은 작업물이 있다면 모두 큐에 추가
            if (jobs[i][0] <= now)
            {
                q.push({ jobs[i][0], jobs[i][1] });
                ++cnt;
            }
            /*
                현재 이전에 요청받은 작업물은 없지만
                큐가 비어있다면 작업물 하나 추가 후 
                현재 시각을 해당 작업 요청시각으로 변경
            */
            else if (q.empty())
            {
                q.push({ jobs[i][0], jobs[i][1] });
                ++cnt;
                now = jobs[i][0];
                break;
            }
        }

        work w = q.top();
        q.pop();

        now += w.w_time;        // 현재시각 : 이번 작업물을 끝마친 시각
        t_stay += now - w.in;   // t_stay에 대기시간(현재 - 작업물 요청시각) 추가 
        ++done;
    }

    return t_stay / N;
}

int main()
{
    /*
    vector<vector<int>> jobs = { {0, 5} ,{1, 2},{5, 5} };
    */
    vector<vector<int>> jobs = { {0, 3} ,{1, 9},{2, 6} };
    cout << solution(jobs);
    return 0;
}