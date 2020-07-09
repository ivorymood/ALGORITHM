//https://programmers.co.kr/learn/courses/30/lessons/12938
//최고의 집합
#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {

    // n개의 자연수로 s를 만들 수 없는 경우
    if (n > s)
    {
        return { -1 };
    }
    
    // 초기에 n개의 자연수는 각각 (s / n)의 값을 가짐
    int qe = s / n;
    vector<int> answer(n, qe);

    // s에서 (int)(s / n) * n만큼을 제하기
    s -= n * qe;
    
    // 뒤에서부터 남은 숫자들을 1씩 더해줌
    for (int i = n - 1; i >= 0; --i)
    {
        ++answer[i];
        --s;
        if (s == 0)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    /*
    int n = 2; int s = 1;
    int n = 2; int s = 8;
    */
    int n = 2; int s = 9;

    vector<int> res = solution(n, s);

    for (int i : res)
    {
        cout << i << ' ';
    }

    return 0;
}