//https://programmers.co.kr/learn/courses/30/lessons/17687
//n���� ����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char digit[] = "0123456789ABCDEF";

// base������ ���ڸ� ���ڿ��� ���� ��ȯ
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
    
    // num�� ������Ű�� ���ڿ��� �̾� �����
    string numbers;
    while (numbers.size() <= end_size)
    {
        numbers += make_n_based_num(num, base);
        ++num;
    }

    // ppl�� ���� ���ڿ� �����ϱ�
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