//https://programmers.co.kr/learn/courses/30/lessons/42883
//큰 수 만들기
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    int size = number.size() - k;

    int strt_idx = 0;
    string answer = "";
    /*
        정답 문자열의 i번째 숫자 구하기
        [i - 1번째 숫자의 다음]부터 ~ [뒤에서 size - i번째 이전] 사이를 탐색
        범위 내에서 가장 큰 숫자 = i번째 정답숫자
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

        // 다음 탐색 범위는 이번 정답 숫자의 다음 인덱스부터
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