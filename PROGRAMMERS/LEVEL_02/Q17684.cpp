//https://programmers.co.kr/learn/courses/30/lessons/17684
//����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {

    // ���� �ʱ�ȭ (���ĺ��� ����)
    const int MAX = 26;
    vector<string> dic(MAX + 1);
    for (int i = 0; i < MAX; ++i)
    {
        dic[i + 1] = i + 'A';
    }

    // LZW ����
    vector<int> answer;
    int strt = 0, len = msg.size();
    while(strt < len)
    {
        int end = strt;
        string now, next;
        vector<string>::iterator it_now, it_next = dic.begin();

        // ���� ��ġ���� ������ ��ϵ� ���� �� �ܾ��, �� �����ܾ� ã��
        while (end <= len)
        {
            ++end;
            next = msg.substr(strt, end - strt);
            it_next = find(dic.begin(), dic.end(), next);

            // ã�� �ܾ ������ ��ϵǾ� ������ now�� ��ȯ�ϰ� ���� �ܾ� ã��
            if (it_next != dic.end())
            {
                now = next;
                it_now = it_next;
            }
            else
            {
                --end;
                break;
            }
        }

        // answer���Ϳ� ���ι�ȣ �߰�
        answer.push_back(it_now - dic.begin());
        // ���ο� �ܾ� ������ �߰�
        dic.push_back(next);
        // ���� �ܾ� ������ end��° ���ں��� 
        strt = end;
    }

    return answer;
}

int main()
{
    /*
    string msg = "TOBEORNOTTOBEORTOBEORNOT";
    string msg = "KAKAO";
    */
    string msg = "ABABABABABABABAB";

    vector<int> rtn = solution(msg);
    for (int i : rtn)
    {
        cout << i << ' ';
    }

    return 0;
}