//https://programmers.co.kr/learn/courses/30/lessons/12946
//�ϳ����� ž
#include <iostream>

#include <string>
#include <vector>

using namespace std;

void move_tower(vector<vector<int>>& answer, int n, int from, int to)
{
    if (n == 0)
    {
        return;
    }

    // 1 ~ N -1 ž �̵� : from -> mid (to ����)
    move_tower(answer, n - 1, from, 6 - from - to);

    // ������ ���� : from -> to �̵�
    answer.push_back({ from, to });

    // 1 ~ N -1 ž �̵� : mid -> to (from ����)
    move_tower(answer, n - 1, 6 - from - to, to);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    // �ϳ���ž �̵� : 1�� -> 3�� (2�� ����)
    move_tower(answer, n, 1, 3);

    return answer;
}

int main()
{
    int n = 2;

    vector<vector<int>> res = solution(n);

    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[0].size(); ++j)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}