//https://programmers.co.kr/learn/courses/30/lessons/42860#qna
//���̽�ƽ
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    
    int len = name.size();
    int answer = 0;
    
    // ���ĺ� �ٲٴ� Ƚ��
    for (int i = 0; i < len; ++i)
    {
        if (name[i] != 'A')
        {
            answer += min(name[i] - 'A', 'Z' + 1 - name[i]);
        }
    }

    // �̵��ϴ� Ƚ�� : ���������θ� �̵����� ����, �߰��� �������� �������� ���� ��
    int left_min = len - 1;
    for (int i = 0; i < len; ++i)
    {
        if (name[i] != 'A')
        {
            int next_idx = i + 1;
            while (next_idx < len && name[next_idx] == 'A')
            {
                ++next_idx;
            }

            int left_move = i * 2 + len - next_idx;
            left_min = min(left_min, left_move);
        }
    }

    return answer += left_min;
}

int main()
{

    /*
    string name = "BABAAAAABAB";
    string name = "JEROEN";
    */
    string name = "JAN";

    cout << solution(name);

    return 0;
}