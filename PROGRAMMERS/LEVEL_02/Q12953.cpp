//https://programmers.co.kr/learn/courses/30/lessons/12953
//N���� �ּҰ����
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// �ִ� �����
int GCD(int A, int B)
{
    if (B == 0)
    {
        return A;
    }
    return GCD(B, A % B);
}

// �ּҰ����
int LCM(int A, int B)
{
    return A * B / GCD(A, B);
}

int solution(vector<int> arr) {

    int t_LCM = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        t_LCM = LCM(t_LCM, arr[i]);
    }
    return t_LCM;
}

int main()
{
    vector<int> arr = { 1, 1, 1, 1 };
    /*
    vector<int> arr = { 1,2,3 };
    vector<int> arr = { 2,6,8,14 };
    */

    cout << solution(arr);
    return 0;
}