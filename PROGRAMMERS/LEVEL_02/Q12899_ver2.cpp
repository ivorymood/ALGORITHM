//https://programmers.co.kr/learn/courses/30/lessons/12899
//124 나라의 숫자 
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(int n) {

    string answer = "";
    // 3 진법 012 = 124나라의 412
    char num[] = { '4', '1', '2' };

    while (n > 0)
    {
        int rest = n % 3;
        n /= 3;

        // 124나라에는 0이 없기 때문에 나머지가 0일 경우, n -= 1
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