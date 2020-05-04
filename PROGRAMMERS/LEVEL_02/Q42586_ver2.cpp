//https://programmers.co.kr/learn/courses/30/lessons/42586
//��ɰ��� 

#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
   
    int day;            // �۾� �Ϸῡ �ɸ��� �ð�
    int max_day = 0;    // �����ɶ����� ��ٷ��� �ϴ� �ð�

    // �տ������� ���������� �������� ī����
    for (int i = 0; i < progresses.size(); i++)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        // �ش� ����� �۾��ð��� ���� ��ɺ��� �� �����ɸ� ��
        if (day > max_day)
        {
            answer.push_back(1);
            max_day = day;
        }
        // �׷��� �ʰ�, ���� ����� �Ϸ�� ������ ��ٷ��� �Ҷ�
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