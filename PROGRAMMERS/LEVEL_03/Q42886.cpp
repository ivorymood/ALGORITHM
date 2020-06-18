//https://programmers.co.kr/learn/courses/30/lessons/42886
//����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {

    // �������� ����
    sort(weight.begin(), weight.end());
   
    int sum = 0;
    for (int w : weight)
    {
        /*
            S[i] = a[0] + ... + a[i] �� �Ҷ�,
            S[i] + 1 < a[i + 1] �̶��
            S[i] + 1 �� ���� �� ����.
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