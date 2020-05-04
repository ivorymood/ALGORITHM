//https://programmers.co.kr/learn/courses/30/lessons/12899
//124 ������ ���� 
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(int n) {

    string answer = "";
    // 3 ���� 012 = 124������ 412
    char num[] = { '4', '1', '2' };

    while (n > 0)
    {
        int rest = n % 3;
        n /= 3;

        // 124���󿡴� 0�� ���� ������ �������� 0�� ���, n -= 1
        if (rest == 0)
        {
            n--;
        }

        answer = num[rest] + answer;
    }

    return answer;
}

int main()
{

    int n;
    cin >> n;
    cout << solution(n);

    return 0;
}