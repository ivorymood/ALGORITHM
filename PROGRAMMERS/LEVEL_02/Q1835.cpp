//https://programmers.co.kr/learn/courses/30/lessons/1835
//단체사진 찍기
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int order[], int n, vector<string> &data)
{
    for (int i = 0 ; i < n; ++i)
    {
        string d = data[i];
        int distance = abs(order[d[0] - 'A'] - order[d[2] - 'A']) - 1;

        printf("%c ~ %c : %d \n", d[0], d[2], distance);

        if (!(d[3] == '=' && distance == d[4])
            && !(d[3] == '>' && distance > d[4])
            && !(d[3] == '<' && distance < d[4]))
        {
            return false;
        }
    }

    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    
    char perm[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    int cnt = 0;

    do {
        int order[26] = { 0, };
        for (int i = 1; i <= 8; ++i)
        {
            order[perm[i - 1] - 'A'] = i;
        }

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