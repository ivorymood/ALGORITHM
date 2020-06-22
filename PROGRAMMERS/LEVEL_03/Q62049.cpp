//https://programmers.co.kr/learn/courses/30/lessons/62049
//��������
#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*
1                0
2        0       0       1
3    0   0   1   0   0   1   1
4  0 0 1 0 0 1 1 0 0 0 1 1 0 1 1
...
*/

void go(vector<int> &v, int depth, int n)
{
    if (depth == n)
    {
        return;
    }

    // n��° ������ 0�� �߾ӿ� �ΰ� ���� ��Ī�Ѵ�. (���ڸ� �����)
    v.push_back(0);
    for (int i = v.size() - 2; i >= 0; --i)
    {
        v.push_back(1 - v[i]);
    }

    go(v, depth + 1, n);
}

vector<int> solution(int n) {

    vector<int> answer;

    go(answer, 0, n);

    return answer;
}

int main()
{
    /*
    
    int n = 2;
    int n = 3;
    */
    int n = 1;

    vector<int> res = solution(n);
    for (int i : res)
    {
        cout << i << ' ';
    }
    return 0;
}