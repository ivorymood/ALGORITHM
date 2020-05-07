//https://programmers.co.kr/learn/courses/30/lessons/42862?language=cpp
//ü����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    // �л� �� �� ����
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
        // ������ ü������ ������
        if (cloth[i] > 0)
        {
            // ���� ü���� �ִ� �л��� �� �Ǵ� �ڿ� ü���� �Ҿ���� �л��� ������
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

    // ���� �������� ���� �л���
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