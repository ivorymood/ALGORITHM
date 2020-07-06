//https://programmers.co.kr/learn/courses/30/lessons/60057
//���ڿ� ����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void concat_string(string &full, string &part, int cnt)
{
    // �ߺ��� 2�̻��̸� ����+���� �����̱�
    if (cnt > 1)
    {
        full += to_string(cnt);
    }
    // �ߺ������� ���ڸ� �����̱�
    full += part;
}

int solution(string s) {

    int len = s.size();
    int answer = len;

    // �ڸ� ���ڿ� ũ�� : 1���� len / 2�� ũ��
    for (int i = 1; i <= len / 2; ++i)
    {
        string last = "";
        string full = "";
        int cnt = 1;

        // �� �κ� ���ڿ� : j�ε������� i�� ũ��� ���ڿ��� �ڸ��� 
        for (int j = 0; j < len; j += i)
        {
            int end = (j + i - 1 < len) ? i : len - j;
            string tmp = s.substr(j, end);

            // ���� ���ڿ��� ���ٸ� ī��Ʈ �߰�
            if (last.compare(tmp) == 0)
            {
                ++cnt;
            }
            // ���� ���ڿ��� �ٸ��ٸ�
            else
            {
                // ��ü ���ڿ��� ī��Ʈ �� �κ� ���ڿ� ���ϱ�
                concat_string(full, last, cnt);

                last = tmp;
                cnt = 1;
            }
        }
        concat_string(full, last, cnt);

        // �ּұ��� ����
        answer = min((int)full.size(), answer);
    }
    
    return answer;
}

int main()
{
    /*
    string s = "ababcdcdababcdcd";
    string s = "aabbaccc";
    string s = "abcabcdede";
    string s = "abcabcabcabcdededededede";
    */
    string s = "xababcdcdababcdcd";


    cout << solution(s);

    return 0;
}