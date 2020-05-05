//https://programmers.co.kr/learn/courses/30/lessons/42842?language=cpp
//카펫
#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    vector<int> answer(2);
    for (int w = 1; w <= red; ++w)
    {
        // red % 가로 == 0, 가로 >= 세로
        if (red % w == 0 && w >= red / w)
        {
            // 가로 * 세로 = 전체 넓이
            if ((w + 2) * (red / w + 2) == brown + red)
            {
                answer[0] = w + 2;
                answer[1] = red / w + 2;
                return answer;
            }
        }
    }
    return answer;
}

int main()
{
    int brown = 8;      int red = 1;
    /*
    int brown = 24;     int red = 24;
    int brown = 10;     int red = 2;
    */

    vector<int> res = solution(brown, red);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << ", ";
    }

    return 0;
}