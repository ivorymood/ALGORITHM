//https://programmers.co.kr/learn/courses/30/lessons/42860#qna
//조이스틱
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    
    int len = name.size();
    int answer = 0;
    
    // 알파벳 바꾸는 횟수
    for (int i = 0; i < len; ++i)
    {
        // A가 아닌 문자면 상하 이동
        if (name[i] != 'A')
        {
            answer += min(name[i] - 'A', 'Z' + 1 - name[i]);
        }
    }

    // 이동하는 횟수 : 오른쪽으로만 이동했을 때와, 중간에 왼쪽으로 턴했을때 값을 비교
    int left_min = len - 1;
    for (int i = 0; i < len; ++i)
    {
        // A가 아닌 문자면 좌우 이동
        if (name[i] != 'A')
        {
            // 다음 A가 아닌 인덱스 구하기
            int next_idx = i + 1;
            while (next_idx < len && name[next_idx] == 'A')
            {
                ++next_idx;
            }

            // i 위치에서의 총 왼쪽 이동 횟수 구하기
            int left_move = i * 2 + len - next_idx;

            // 최소 이동횟수
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