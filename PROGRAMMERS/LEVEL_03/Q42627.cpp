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

struct compare {
    bool operator()(work& a, work& b)
    {
        return a.w_time > b.w_time;
    }
};

int solution(vector<vector<int>> jobs) {

    sort(jobs.begin(), jobs.end());

    priority_queue<work, vector<work>, compare> q;

    int N = jobs.size();
    int now = 0, cnt = 0, sum = 0, done = 0;

    while (N - done)
    {
        for (int i = cnt; i < N; ++i)
        {
            if (jobs[i][0] <= now)
            {
                q.push({ jobs[i][0], jobs[i][1] });
                ++cnt;
            }
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

        now += w.w_time;
        sum += now - w.in;
        ++done;
    }

    return sum / N;
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