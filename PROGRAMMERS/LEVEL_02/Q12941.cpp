//https://programmers.co.kr/learn/courses/30/lessons/12941
//�ּڰ� �����
#include <iostream>

#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    // A: ��������, B: �������� ����
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), [](int x, int y) {
        return x > y;
        });

    // �� �ڸ��� ���� ���ؼ� ���ϱ�
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