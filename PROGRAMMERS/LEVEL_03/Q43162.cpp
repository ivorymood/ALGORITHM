//https://programmers.co.kr/learn/courses/30/lessons/43162
//��Ʈ��ũ
#include <iostream>

#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &computers, vector<bool> &check, int node, int n)
{
    for (int i = 0; i < n; ++i)
    {
        // ���� ���� ����Ǿ� �ְ� ���� �湮���� ����� dfs�Լ� ���ȣ�� 
        if (computers[node][i] == 1 && !check[i])
        {
            check[i] = true;
            dfs(computers, check, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    vector<bool> check(n);
    int network = 0;
    
    // ���� �湮���� ��忡������ ��������� dfsŽ��
    for (int i = 0; i < n; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            dfs(computers, check, i, n);
            // �ϳ��� �׷����� ������ ī����
            ++network;
        }
    }

    return network;
}

int main()
{
    /*
    int n = 3; vector<vector<int>> computers = { {1, 1, 0} ,{1, 1, 1},{0, 1, 1} };
    */
    int n = 3; vector<vector<int>> computers = { {1, 1, 0} ,{1, 1, 0},{0, 0, 1} };

    cout << solution(n, computers);

    return 0;
}