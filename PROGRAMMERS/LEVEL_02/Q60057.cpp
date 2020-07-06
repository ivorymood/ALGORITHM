//https://programmers.co.kr/learn/courses/30/lessons/60057
//문자열 압축
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void concat_string(string &full, string &part, int cnt)
{
    // 중복이 2이상이면 숫자+문자 덧붙이기
    if (cnt > 1)
    {
        full += to_string(cnt);
    }
    // 중복없으면 문자만 덧붙이기
    full += part;
}

int solution(string s) {

    int len = s.size();
    int answer = len;

    // 자를 문자열 크기 : 1부터 len / 2의 크기
    for (int i = 1; i <= len / 2; ++i)
    {
        string last = "";
        string full = "";
        int cnt = 1;

        // 각 부분 문자열 : j인덱스부터 i의 크기로 문자열을 자르기 
        for (int j = 0; j < len; j += i)
        {
            int end = (j + i - 1 < len) ? i : len - j;
            string tmp = s.substr(j, end);

            // 이전 문자열과 같다면 카운트 추가
            if (last.compare(tmp) == 0)
            {
                ++cnt;
            }
            // 이전 문자열과 다르다면
            else
            {
                // 전체 문자열에 카운트 및 부분 문자열 더하기
                concat_string(full, last, cnt);

                last = tmp;
                cnt = 1;
            }
        }
        concat_string(full, last, cnt);

        // 최소길이 갱신
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