//https://programmers.co.kr/learn/courses/30/lessons/17684
//압축
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {

    // 사전 초기화 (알파벳만 포함)
    const int MAX = 26;
    vector<string> dic(MAX + 1);
    for (int i = 0; i < MAX; ++i)
    {
        dic[i + 1] = i + 'A';
    }

    // LZW 압축
    vector<int> answer;
    int strt = 0, len = msg.size();
    while(strt < len)
    {
        int end = strt;
        string now, next;
        vector<string>::iterator it_now, it_next = dic.begin();

        // 현재 위치에서 사전에 등록된 가장 긴 단어와, 그 다음단어 찾기
        while (end <= len)
        {
            ++end;
            next = msg.substr(strt, end - strt);
            it_next = find(dic.begin(), dic.end(), next);

            // 찾은 단어가 사전에 등록되어 있으면 now로 교환하고 다음 단어 찾기
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

        // answer벡터에 색인번호 추가
        answer.push_back(it_now - dic.begin());
        // 새로운 단어 사전에 추가
        dic.push_back(next);
        // 다음 단어 시작은 end번째 글자부터 
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