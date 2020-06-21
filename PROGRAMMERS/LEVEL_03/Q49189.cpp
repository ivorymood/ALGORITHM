//https://programmers.co.kr/learn/courses/30/lessons/49189
//���� �� ���
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs_get_max_dist_cnt(vector<vector<int>> & adj_list, int n)
{
    // 0����忡�� �Ÿ� 1���� ����
    // (�Ÿ��� 0�� �ƴϸ� �湮�� ������ �Ǵ��ϱ� ����)
    vector<int> dists(n);
    queue<pair<int, int>> q;
    q.push({0, 1});
    dists[0] = 1;
    int max_dist = 0;

    while (!q.empty())
    {
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();

        // ���� ��� �� ���� �湮���� ���� ��带 �Ÿ� + 1 �� �� ť�� push
        for (int i = 0; i < adj_list[now].size(); ++i)
        {
            int next = adj_list[now][i];
            if (dists[next] == 0)
            {
                // 0�� ������ �Ÿ� ����
                dists[next] = dist + 1;
                q.push({next, dist + 1});

                // �ִ� �Ÿ� ����
                max_dist = max(dist, max_dist);
            }
        }
    }

    // 0�� ���� ���� �� �Ÿ��� ��� ���� ī���� �� ��ȯ
    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dists[i] == max_dist)
        {
            ++answer;
        }
    }
    return answer;
}

int solution(int n, vector<vector<int>> edge) {

    // ���� ����Ʈ �����
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < edge.size(); ++i)
    {
        int A = edge[i][0] - 1;
        int B = edge[i][1] - 1;

        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }

    // bfsŽ������ ���� �� �Ÿ��� ��� ���� ���ϱ�
    return bfs_get_max_dist_cnt(adj_list, n);
}

int main()
{
    int n = 6; vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, edge);
}