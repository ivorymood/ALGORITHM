//https://www.acmicpc.net/problem/17085
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
using d_vector = vector<vector<T>>;

struct pos
{
    int y, x;
};

// right, down, left, up
int dr_y[] = {0, 1, 0, -1};
int dr_x[] = {1, 0, -1, 0};
int N, M;
vector<string> board;

// 십자가(4방향) 확장 가능한지 확인
bool is_spannable(d_vector<bool> &visit, pos &p, int len)
{
    for (int k = 0; k < 4; ++k)
    {
        int ny = p.y + dr_y[k] * len;
        int nx = p.x + dr_x[k] * len;

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] == '.' || visit[ny][nx])
        {
            return false;
        }
    }
    return true;
}

// 방문 체크 복구
void revoke_visit(d_vector<bool> &visit, pos &p, int len)
{
    while (len >= 0)
    {
        for (int k = 0; k < 4; ++k)
        {
            int ny = p.y + dr_y[k] * len;
            int nx = p.x + dr_x[k] * len;

            visit[ny][nx] = false;
        }
        --len;
    }
}

int get_second_cross_size(d_vector<bool> &visit)
{
    int max_size = 0;

    // 보드 전체 탐색
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            // size_2 : 두번째 십자가 위치가 [i, j]일때 두번째 십자가 크기
            pos cross_2 = {i, j};
            int size_2 = 0;
            int len = 0;

            // 확장 가능하면
            while (is_spannable(visit, cross_2, len))
            {
                // 4방향 방문 체크
                for (int k = 0; k < 4; ++k)
                {
                    int ny = cross_2.y + dr_y[k] * len;
                    int nx = cross_2.x + dr_x[k] * len;
                    visit[ny][nx] = true;
                }
                size_2 = 1 + len * 4;
                ++len;
            }

            revoke_visit(visit, cross_2, len - 1);
            max_size = max(size_2, max_size);
        }
    }
    return max_size;
}

int solve()
{
    int ans = 0;
    d_vector<bool> visit(N, vector<bool>(M));

    // 전체 보드 탐색
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            // size_1 : 첫번째 십자가 위치가 [i, j]일때 첫번째 십자가 크기
            pos cross_1 = {i, j};
            int size_1 = 0;
            int size_2 = 0;
            int len = 0;

            // 확장 가능하면
            while (is_spannable(visit, cross_1, len))
            {
                // 4방향 방문 체크
                for (int k = 0; k < 4; ++k)
                {
                    int ny = cross_1.y + dr_y[k] * len;
                    int nx = cross_1.x + dr_x[k] * len;
                    visit[ny][nx] = true;
                }

                size_1 = 1 + 4 * len;
                ++len;

                // size_2 : 첫번째 십자가 위치가 [i, j]일때 두번째 십자가 크기
                size_2 = get_second_cross_size(visit);
            }

            revoke_visit(visit, cross_1, len - 1);
            ans = max(size_1 * size_2, ans);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> N >> M;
    board = vector<string>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }

    // 출력 : 두 십자가 넓이 곱의 최대값
    cout << solve();

    return 0;
}