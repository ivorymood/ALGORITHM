//https://programmers.co.kr/learn/courses/30/lessons/42883
//큰 수 만들기
#include <iostream>

#include <string>

using namespace std;

string solution(string number, int k) {

    /*
        1. A[0 ~ k - 1], B[k ~ size] 두개의 구간으로 number 나누기
        2. A의 맨 뒤에서부터, B의 맨 앞에서부터 비교하기 --> Ai >= Bj 면 교환 
        3. 반복
    */
    for (int i = k - 1; i >= 0; --i)
    {
        for (int j = k; j < number.size(); ++j)
        {
            if (number[i] < number[j])
            {
                break;
            }
            int temp = number[i];
            number[i] = number[j];
            number[j] = temp;
        }
    }
    return number.substr(k);
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