//https://programmers.co.kr/learn/courses/30/lessons/17687
//n진수 게임
#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

char digit[] = "0123456789ABCDEF";

// base진법의 숫자를 만들어서 stack에 문자를 push
void make_n_based_num(stack<char>& s, int n, const int base)
{
    if (n == 0)
    {
        s.push(digit[0]);
        return;
    }

    while (n)
    {
        s.push(digit[n % base]);
        n /= base;
    }
}

string solution(int base, int end_cnt, int ppl, int order) {

    int plused = 0, num = 0, stream_idx = 0;
    stack<char> s;
    string answer = "";

    --order;

    while (plused < end_cnt)
    {
        // num을 base진법의 수로 만들어서 각 문자를 stack에 push
        make_n_based_num(s, num, base);

        // 차례가 돌아올때에 stack에 저장된 문자를 answer 저장하기
        while (!s.empty() && plused < end_cnt)
        {
            if (stream_idx % ppl == order)
            {
                answer += s.top();
                ++plused;
            }
            // 차례가 아니면 pop
            s.pop();
            ++stream_idx;
        }
        ++num;
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