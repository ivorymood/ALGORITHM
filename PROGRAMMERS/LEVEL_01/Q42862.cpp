//https://programmers.co.kr/learn/courses/30/lessons/42862?language=cpp
//체육복
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    // 학생 별 옷 개수
    vector<int> cloth(n + 2);
    for (int i = 0; i < lost.size(); ++i)
    {
        --cloth[lost[i]];
    }
    for (int i = 0; i < reserve.size(); ++i)
    {
        ++cloth[reserve[i]];
    }

    for (int i = 1; i <= n; ++i)
    {
        // 여분의 체육복이 있으면
        if (cloth[i] > 0)
        {
            // 여분 체육복 있는 학생의 앞 또는 뒤에 체육복 잃어버린 학생이 있으면
            if (cloth[i - 1] < 0)
            {
                cloth[i] = cloth[i - 1] = 0;
            }
            else if (cloth[i + 1] < 0)
            {
                cloth[i] = cloth[i + 1] = 0;
            }
        }
    }

    // 옷이 부족하지 않은 학생수
    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cloth[i] >= 0)
        {
            ++answer;
        }
    }
    return answer;
}

int main()
{
    /*
    int n = 5; vector<int> lost = { 2, 4 }; vector<int> reserve = { 1, 3, 5 };
    int n = 5; vector<int> lost = { 2, 4 }; vector<int> reserve = { 3 };
    */
    int n = 3; vector<int> lost = { 3 }; vector<int> reserve = { 1 };

    cout << solution(n, lost, reserve);

    return 0;
}