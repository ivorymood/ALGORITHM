//https://programmers.co.kr/learn/courses/30/lessons/12978
//���
#include <iostream>

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

// 1�� �������� K�� �ð����� ����� �� �ִ� ���� ���� ���ϱ�
int bfs(vector<vector<int>> &v_adj, int N, int K)
{
    // 1�� �������� N��° ���������� �ּ� �ð��� ����
    vector<int> min_dist(N + 1, INF);
    
    // 1���������� 0�� �̵��ð����� ����
    queue<pair<int, int>> q;
    q.push({1, 0});
    min_dist[1] = 0;

    while (!q.empty())
    {
        // ���� ������ ���ݱ��� �̵��� �ð�
        int now = q.front().first;
        int time = q.front().second;
        q.pop();

        for (int next = 1; next <= N; ++next)
        {
            int n_time = v_adj[now][next];

            // ���ΰ� ������ continue
            if (n_time == INF)
            {
                continue;
            }

            /*
                total = ���ݱ��� �̵��� �ð� + ������������ �ð� 
                
                total <= K�̰�, 1���������� next���������� �ּ� �Ÿ��� total���� ũ��
                �ּҰ� ���� �� queue�� push
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
        ���� �迭 �����
        A-B�� �����ϴ� ���ΰ� ������ ���� ��, �ּ��� �� ���� 
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
    
    // 1�� �������� K�� �ð����� ����� �� �ִ� ���� ���� ���ϱ�
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