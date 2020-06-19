//https://programmers.co.kr/learn/courses/30/lessons/42627
//��ũ ��Ʈ�ѷ�
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

    // ��û�ð� ������������ ����
    sort(jobs.begin(), jobs.end());

    // �۾��� �۾��ð� ������������ �����ϴ� �켱���� ť
    //priority_queue<work, vector<work>, compare> q;
    priority_queue<work, vector<work>, decltype(&my_compare)> q(my_compare);

    int N = jobs.size();
    int now = 0, cnt = 0, t_stay = 0, done = 0;

    // ��� �۾��� ��ĥ ������ �ݺ���
    while (N - done)
    {
        // ���� �߰����� ���� �۾��� ���� �ݺ���
        for (int i = cnt; i < N; ++i)
        {
            // ���� ������ ��û���� �۾����� �ִٸ� ��� ť�� �߰�
            if (jobs[i][0] <= now)
            {
                q.push({ jobs[i][0], jobs[i][1] });
                ++cnt;
            }
            /*
                ���� ������ ��û���� �۾����� ������
                ť�� ����ִٸ� �۾��� �ϳ� �߰� �� 
                ���� �ð��� �ش� �۾� ��û�ð����� ����
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

        now += w.w_time;        // ����ð� : �̹� �۾����� ����ģ �ð�
        t_stay += now - w.in;   // t_stay�� ���ð�(���� - �۾��� ��û�ð�) �߰� 
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