//https://programmers.co.kr/learn/courses/30/lessons/43162
//네트워크
#include <iostream>

#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &computers, vector<bool> &check, int node, int n)
{
    for (int i = 0; i < n; ++i)
    {
        // 현재 노드와 연결되어 있고 아직 방문안한 노드라면 dfs함수 재귀호출 
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
    
    // 아직 방문안한 노드에서부터 인접행렬을 dfs탐색
    for (int i = 0; i < n; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            dfs(computers, check, i, n);
            // 하나의 그래프가 끝나면 카운팅
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