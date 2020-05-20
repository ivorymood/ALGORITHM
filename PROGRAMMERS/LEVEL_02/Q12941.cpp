//https://programmers.co.kr/learn/courses/30/lessons/12941
//최솟값 만들기
#include <iostream>

#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    // A: 오름차순, B: 내림차순 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), [](int x, int y) {
        return x > y;
        });

    // 각 자리의 수를 곱해서 더하기
    int answer = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        answer += A[i] * B[i];
    }

    return answer;
}

int main()
{
    /*
    vector<int> A = { 1, 4, 2 }; vector<int> B = { 5, 4, 4 };
    */
    vector<int> A = { 1,2 }; vector<int> B = { 3,4 };

    cout << solution(A, B);

    return 0;
}