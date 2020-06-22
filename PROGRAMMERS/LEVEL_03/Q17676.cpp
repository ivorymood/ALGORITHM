//https://programmers.co.kr/learn/courses/30/lessons/17676
//[1��] �߼� Ʈ����
#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

enum {START, END};

struct w_time
{
    int ms, state;
};

int solution(vector<string> lines) {


    vector<w_time> times;
    for (int i = 0; i < lines.size(); ++i)
    {
        // �α׵����͸� ms�� ������ ȯ��
        stringstream sstr(lines[i]);
        string end;
        sstr >> end >> end;

        int hh = ((end[0] - '0') * 10 + (end[1] - '0')) * 60 * 60;
        int mm = ((end[3] - '0') * 10 + (end[4] - '0')) * 60;
        int ss = ((end[6] - '0') * 10 + (end[7] - '0'));
        int ms = ((end[9] - '0') * 100 + (end[10] - '0') * 10 + (end[11] - '0'));
        
        ms += ((hh + mm + ss) * 1000);
        
        double work;
        sstr >> work;

        // ���۽ð��� ���ð��� �󺧸��Ͽ� times���Ϳ� push
        times.push_back({ ms - (int)(work * 1000) + 1, START });
        times.push_back({ ms + 999, END });
    }

    // �۾� ����/�� �ð� ����� 1. �ð�, 2. ����->�� ������ �������� ����
    sort(times.begin(), times.end(), [&times](w_time&a, w_time&b) {
        if (a.ms != b.ms)
        {
            return a.ms < b.ms;
        }
        return a.state < b.state;
        });


    int working = 0, max_cnt = 0;
    for (int i = 0; i < times.size(); ++i)
    {
        // �� �۾������� ���۵Ǹ� working + 1
        if (times[i].state == START)
        {
            ++working;
        }
        // �� �۾������� ����Ǹ� working - 1
        else 
        {
            --working;
        }

        // ���ð��� �ִ� �۾� ���� ���ϱ�
        max_cnt = max(working, max_cnt);
    }

    return max_cnt;
}

int main()
{
    vector<string> lines = { "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" }; //1
    /*
    vector<string> lines = { "2016-09-15 00:00:00.000 3s"}; //1
    vector<string> lines = { "2016-09-15 23:59:59.999 0.001s"}; //1
    vector<string> lines = { "2016-09-15 00:00:00.000 2.3s", "2016-09-15 23:59:59.999 0.1s" }; //1
    vector<string> lines = { "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" }; //2
    vector<string> lines = { "2016-09-15 20:59:57.421 0.351s",
                            "2016-09-15 20:59:58.233 1.181s",
                            "2016-09-15 20:59:58.299 0.8s",
                            "2016-09-15 20:59:58.688 1.041s",
                            "2016-09-15 20:59:59.591 1.412s",
                            "2016-09-15 21:00:00.464 1.466s",
                            "2016-09-15 21:00:00.741 1.581s",
                            "2016-09-15 21:00:00.748 2.31s",
                            "2016-09-15 21:00:00.966 0.381s",
                            "2016-09-15 21:00:02.066 2.62s" }; //7
    */

    cout << solution(lines);

    return 0;
}