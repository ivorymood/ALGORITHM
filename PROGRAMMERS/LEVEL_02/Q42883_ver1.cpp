//https://programmers.co.kr/learn/courses/30/lessons/42883
//ū �� �����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    int size = number.size() - k;

    int strt_idx = 0;
    string answer = "";
    /*
        ���� ���ڿ��� i��° ���� ���ϱ�
        [i - 1��° ������ ����]���� ~ [�ڿ��� size - i��° ����] ���̸� Ž��
        ���� ������ ���� ū ���� = i��° �������
    */
    for (int i = 0; i < size; ++i)
    {
        int max_idx = strt_idx;
        char max_num = number[max_idx];
        for (int j = strt_idx; j < k + i + 1; ++j)
        {
            if (max_num < number[j])
            {
                max_idx = j;
                max_num = number[j];
            }
        }

        // ���� Ž�� ������ �̹� ���� ������ ���� �ε�������
        strt_idx = max_idx + 1;
        answer += max_num;
    }

    return answer;
}

int main()
{
    /*
    string number = "1231234";      int k = 3;
    string number = "4177252841";   int k = 4;
    string number = "91919191";   int k = 1;
    */
    string number = "1941";         int k = 2;

    cout << solution(number, k);

    return 0;
}