//https://programmers.co.kr/learn/courses/30/lessons/1835
//단체사진 찍기
#include <iostream>

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool check(int order[], int n, vector<string> data)
{
    for (int i = 0; i < n; ++i)
    {
        string d = data[i];
        // 두 문자 위치 사이의 간격
        int distance = abs(order[d[0] - 'A'] - order[d[2] - 'A']) - 1;

        // 문제 조건에 일치하지 않으면 false
        if (!(d[3] == '=' && distance == d[4] - '0')
            && !(d[3] == '>' && distance > d[4] - '0')
            && !(d[3] == '<' && distance < d[4] - '0'))
        {
            return false;
        }
    }

    // 문제 조건이 모두 일치하면 true
    return true;
}

int solution(int n, vector<string> data) {

    char perm[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    int cnt = 0;

    // 오름차순 순열 -> 위치값 저장
    do {
        int order[26] = { 0, };
        for (int i = 0; i < 8; ++i)
        {
            order[perm[i] - 'A'] = i + 1;
        }

        // 해당 순열이 조건에 맞으면 cnt++
        if (check(order, n, data))
        {
            ++cnt;
        }

    } while (next_permutation(perm, perm + 8));

    return cnt;
}

int main()
{
    int n = 2;  vector<string> data = { "N~F=0", "R~T>2" };
    /*
    int n = 2;  vector<string> data = { "M~C<2", "C~M>1" };
    */
    cout << solution(n, data);

    return 0;
}