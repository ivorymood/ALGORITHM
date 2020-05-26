//https://programmers.co.kr/learn/courses/30/lessons/17687
//n���� ����
#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

char digit[] = "0123456789ABCDEF";

// base������ ���ڸ� ���� stack�� ���ڸ� push
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
        // num�� base������ ���� ���� �� ���ڸ� stack�� push
        make_n_based_num(s, num, base);

        // ���ʰ� ���ƿö��� stack�� ����� ���ڸ� answer �����ϱ�
        while (!s.empty() && plused < end_cnt)
        {
            if (stream_idx % ppl == order)
            {
                answer += s.top();
                ++plused;
            }
            // ���ʰ� �ƴϸ� pop
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