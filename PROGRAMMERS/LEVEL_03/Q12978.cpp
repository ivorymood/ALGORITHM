//https://programmers.co.kr/learn/courses/30/lessons/12978
//배달
#include <iostream>

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

// 1번 마을에서 K의 시간내에 배달할 수 있는 마을 개수 구하기
int bfs(vector<vector<int>> &v_adj, int N, int K)
{
    // 1번 마을에서 N번째 마을까지의 최소 시간을 저장
    vector<int> min_dist(N + 1, INF);
    
    // 1번마을에서 0의 이동시간으로 시작
    queue<pair<int, int>> q;
    q.push({1, 0});
    min_dist[1] = 0;

    while (!q.empty())
    {
        // 현재 마을과 지금까지 이동한 시간
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        for (int next = 1; next <= N; ++next)
        {
            int n_time = v_adj[now][next];

            // 도로가 없으면 continue
            if (n_time == INF)
            {
                continue;
            }

            /*
                total = 지금까지 이동한 시간 + 다음마을까지 시간 
                
                total <= K이고, 1번마을에서 next마을까지의 최소 거리가 total보다 크면
                최소값 갱신 후 queue에 push
            */
            int total = time + n_time;
            if (total <= K && min_dist[next] > total)
            {
                min_dist[next] = total;
                q.push(make_pair(next, total));
            }
        }
    }

    int cnt = 0;
    for (int d : min_dist)
    {
        if (d != INF)
        {
            ++cnt;
        }
    }
    return cnt;
}

int solution(int N, vector<vector<int>> road, int K) {
   
    /*
        인접 배열 만들기
        A-B를 연결하는 도로가 여러개 있을 때, 최소의 값 저장 
    */
    vector<vector<int>> adj(N + 1, vector<int>(N + 1, INF));
    for (vector<int> &v : road)
    {
        if (adj[v[0]][v[1]] > v[2])
        {
            adj[v[0]][v[1]] = v[2];
            adj[v[1]][v[0]] = v[2];
        }
    }
    
    // 1번 마을에서 K의 시간내에 배달할 수 있는 마을 개수 구하기
    return  bfs(adj, N, K);
}

int main()
{
    /*
    int N = 5; int K = 3; // 4
    vector<vector<int> > road = {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}};
    */
    int N = 6; int K = 4; // 4
    vector<vector<int> > road = {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}};

    cout << solution(N, road, K);

    return 0;
}