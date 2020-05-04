//https://programmers.co.kr/learn/courses/30/lessons/42841?language=cpp
//���� �߱�
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int const MAX = 3;
vector<vector<int>> testcase;
int cnt;

/*
    �־��� �׽�Ʈ ���̽��� �� �����ϴ��� �˻��ϱ�

    �� �׽�Ʈ ���ڸ� ������ڿ� ���Ͽ� n��Ʈ����ũ m���� ���Դٸ�, 
    ������ ������ڵ� �� �׽�Ʈ ���ڿ� ���ϸ� n��Ʈ����ũ m���� ���� ��.
*/
bool possible(int num)
{
    for (int i = 0; i < testcase.size(); i++)
    {
        if (num == testcase[i][0])
        {
            return false;
        }

        int strike = 0;
        int ball = 0;
        string str_num = to_string(num);
        string str_test = to_string(testcase[i][0]);

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (str_num[i] == str_test[j])
                {
                    if (i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }

        if (strike != testcase[i][1] || ball != testcase[i][2])
        {
            return false;
        }
    }

    return true;
}

void perm(int output, bool visited[], int depth, int r)
{
    // depth�� 3�� �����ϸ� ������� ���� �˻�
    if (depth == r)
    {
        if (possible(output))
        {
            cnt++;
        }
        return;
    }

    // 1~9������ ���� �ٸ� ���� 3�ڸ��� �����
    for (int i = 1; i <= 9; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            output = output * 10 + i;
            perm(output, visited, depth + 1, r);
            output /= 10;
            visited[i] = false;
        }
    }
}

int solution(vector<vector<int>> baseball) {

    // ����vector�� ������ ��ȯ
    testcase.swap(baseball);

    bool visited[10] = { 0, };

    // 3�ڸ��� ���ڸ� ������ ��, �־��� ���� �������θ� �˻��ϱ�
    perm(0, visited, 0, 3);

    return cnt;
}

int main()
{
    vector<vector<int>> baseball = { {123, 1, 1} ,{356, 1, 0},{327, 2, 0},{489, 0, 1} };

    cout << solution(baseball);

    return 0;
}