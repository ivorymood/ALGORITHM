//https://programmers.co.kr/learn/courses/30/lessons/42747?language=cpp
//H-Index
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), [](int a, int b) {
        return a > b;
        });

    // H_Index : h번 이상 인용된 논문이 h편 이상
    // H_Index 조건을 충족하지 않으면 break
    int h = 0;
    while (h++ <= citations.size())
    {
        if (citations[h - 1] < h)
        {
            break;
        }
    }
    return h - 1;
}

int main()
{
    vector<int> citations = { 3, 0, 6, 1, 5 };

    cout << solution(citations);
    
    return 0;
}