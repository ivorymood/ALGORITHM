//https://www.acmicpc.net/problem/11060
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
const int MAX = 1000;

void get_min_jump_cnt(vector<int> &maze, vector<int> &DP, int strt)
{
    for (int i = maze[strt]; i > 0; --i)
    {
        int next = strt + i;
        if (next < N && DP[next] > DP[strt] + 1)
        {
            DP[next] = DP[strt] + 1;
            get_min_jump_cnt(maze, DP, next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> N;
    vector<int> maze(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> maze[i];
    }

    // DP[i] : i번째 칸에 오기까지 최소로 jump한 횟수
    vector<int> DP(N, MAX);
    DP[0] = 0;

    get_min_jump_cnt(maze, DP, 0);

    // 출력
    cout << (DP[N - 1] == MAX ? -1 : DP[N - 1]);

    return 0;
}