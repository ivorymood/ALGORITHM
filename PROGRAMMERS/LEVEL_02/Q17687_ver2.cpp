//https://programmers.co.kr/learn/courses/30/lessons/17687
//n진수 게임
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char digit[] = "0123456789ABCDEF";

// base진법의 숫자를 문자열로 만들어서 반환
string make_n_based_num(int n, const int base)
{
    if (n == 0)
    {
        return "0";
    }

    string num;
    while (n)
    {
        num += digit[n % base];
        n /= base;
    }

    reverse(num.begin(), num.end());
    
    return num;
}

string solution(int base, int end_cnt, int ppl, int order) {
    
    int plused = 0, num = 0, end_size = end_cnt * ppl;
    
    // num을 증가시키며 문자열로 이어 만들기
    string numbers;
    while (numbers.size() <= end_size)
    {
        numbers += make_n_based_num(num, base);
        ++num;
    }

    // ppl씩 띄어가며 문자열 저장하기
    string answer;
    for (int i = order - 1; i < numbers.size() && plused < end_cnt; i += ppl)
    {
        answer += numbers[i];
        ++plused;
    }

    return answer;
}

int main()
{
    /*
    int n = 16; int t = 16; int m = 2; int p = 1;
    int n = 2; int t = 4; int m = 2; int p = 1;
    */
    int n = 16; int t = 16; int m = 2; int p = 2;

    cout << solution(n, t, m, p);

    return 0;
}