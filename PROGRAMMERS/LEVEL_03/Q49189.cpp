//https://programmers.co.kr/learn/courses/30/lessons/49189
//가장 먼 노드
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs_get_max_dist_cnt(vector<vector<int>> & adj_list, int n)
{
    // 0번노드에서 거리 1부터 시작
    // (거리가 0이 아니면 방문한 것으로 판단하기 위해)
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

        // 인접 노드 중 아직 방문하지 않은 노드를 거리 + 1 한 후 큐에 push
        for (int i = 0; i < adj_list[now].size(); ++i)
        {
            int next = adj_list[now][i];
            if (dists[next] == 0)
            {
                // 0번 노드와의 거리 저장
                dists[next] = dist + 1;
                q.push({next, dist + 1});

                // 최대 거리 갱신
                max_dist = max(dist, max_dist);
            }
        }
    }

    // 0번 노드와 가장 먼 거리의 노드 개수 카운팅 후 반환
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

    // 인접 리스트 만들기
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < edge.size(); ++i)
    {
        int A = edge[i][0] - 1;
        int B = edge[i][1] - 1;

        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }

    // bfs탐색으로 가장 먼 거리의 노드 개수 구하기
    return bfs_get_max_dist_cnt(adj_list, n);
}

int main()
{
    int n = 6; vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, edge);
}