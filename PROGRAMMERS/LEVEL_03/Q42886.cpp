//https://programmers.co.kr/learn/courses/30/lessons/42886
//저울
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {

    // 오름차순 정렬
    sort(weight.begin(), weight.end());
   
    int sum = 0;
    for (int w : weight)
    {
        /*
            S[i] = a[0] + ... + a[i] 라 할때,
            S[i] + 1 < a[i + 1] 이라면
            S[i] + 1 은 만들 수 없다.
        */
        if (sum + 1 < w)
        {
            break;
        }
        sum += w;
    }

    return sum + 1;
}

int main()
{
    /*
    vector<int> weight = { 3, 1, 6, 2, 7, 30, 1 };
    */
    vector<int> weight = { 1, 1, 3 };
    
    cout << solution(weight);

    return 0;
}