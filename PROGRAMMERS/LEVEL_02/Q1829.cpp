//https://programmers.co.kr/learn/courses/30/lessons/1829
//īī�� ������ �÷�����
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int M, N;
// ������, �Ʒ���, ����, ����
vector<pair<int, int>> drx = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void dfs(vector<vector<int>> &picture, vector<int> &cnt, int x, int y)
{
    // �ش� �� ���� ���� + 1
    ++*(cnt.end() - 1);
    int num = picture[x][y];
    
    // �ѹ� ������ ������ 0���� �ٲٱ�
    picture[x][y] = 0;

    // ���� (x, y)ĭ�� ���� ���� ������ �ִ��� 4 �������� Ž�� 
    for (int k = 0; k < 4; ++k)
    {
        int newX = x + drx[k].first;
        int newY = y + drx[k].second;
        
        if (newX >= 0 && newX < M && newY >= 0 && newY < N && num == picture[newX][newY])
        {
            // ���� ������ 4���� Ž���� ���� dfs ���ȣ��
            dfs(picture, cnt, newX, newY);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    M = m;
    N = n;
    vector<int> cnt;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // ��ĥ�� "���ο�" ������ ������ ���� �� ���� Ž�� ����
            if (picture[i][j] > 0)
            {
                cnt.push_back(0);
                dfs(picture, cnt, i, j);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = cnt.size();
    answer[1] = *max_element(cnt.begin(), cnt.end());

    return answer;
}

int main()
{
    /*


    vector<vector<int>> picture = { {1, 1, 1, 0},
                                    {1, 1, 1, 0},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 1} };
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = { {1, 1, 1, 0},
                                    {1, 2, 2, 0},
                                    {1, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 3},
                                    {0, 0, 0, 3} };
    */

    int m = 13;
    int n = 16;
    vector<vector<int>> picture = { {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
                                    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                    { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
                                    { 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0 },
                                    { 0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0 },
                                    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                                    { 0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0 },
                                    { 0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0 },
                                    { 0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0 },
                                    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } };


    vector<int> res = solution(m, n, picture);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << ' ';
    }

    return 0;
}