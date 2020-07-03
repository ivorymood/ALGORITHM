//https://programmers.co.kr/learn/courses/30/lessons/60063
//블록 이동하기
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct pos {
    int x, y;
};

struct robot {
    pos p;
    int dir, cnt;
};

const int MAX = 100;
int N;
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
int r_x[] = {-1, 1, 1, 1, -1, 1, -1, -1};
int r_y[] = {1, 1, -1, 1, -1, -1, -1, 1};

vector<vector<int>> m_board;
bool visited[MAX][MAX][4];

bool check(pos &A, pos &B, int dir_A, int dir_B)
{
    if (A.x < 0 || A.x >= N || A.y < 0 || A.y >= N
        || B.x < 0 || B.x >= N || B.y < 0 || B.y >= N)
    {
        return false;
    }

    if (m_board[A.x][A.y] == 1 || m_board[B.x][B.y] == 1)
    {
        return false;
    }

    if (visited[A.x][A.y][dir_A] || visited[B.x][B.y][dir_B])
    {
        return false;
    }

    return true;
}

void push_if_ok(queue<robot>& q, pos &A, int dir_A, int cnt)
{
    pos B = { A.x + dr_x[dir_A], A.y + dr_y[dir_A] };
    int dir_B = (dir_A + 2) % 4;

    // 정합성 체크
    if (check(A, B, dir_A, dir_B))
    {
        q.push({ A, dir_A, cnt });
        q.push({ B, dir_B, cnt });

        /*
            A - B 와 B - A는 같은 위치를 뜻한다
        */
        visited[A.x][A.y][dir_A] = 1;
        visited[B.x][B.y][dir_B] = 1;
    }
}

int bfs()
{
    queue<robot> qq;
    qq.push({ {0, 0}, 0, 0} );
    qq.push({ {0, 1}, 2, 0} );
    visited[0][0][0] = true;
    visited[0][1][2] = true;

    while (!qq.empty())
    {
        robot &r = qq.front();
        pos p = r.p;
        int dir = r.dir;
        int cnt = r.cnt;
        qq.pop();

        printf("p[%d][%d]  dir : %d    cnt : %d\n", p.x, p.y, dir, cnt);

        // [N][N]에 도착하면 이동횟수 반환
        if ((p.x == N - 1 && p.y == N - 1) 
            || (p.x + dr_x[dir] == N - 1 && p.y + dr_y[dir] == N - 1))
        {
            return cnt;
        }

        // 4방향 이동
        for (int i = 0; i < 4; ++i)
        {
            pos n_p = { p.x + dr_x[i], p.y + dr_y[i] };

            push_if_ok(qq, n_p, dir, cnt + 1);
        }


        // 회전
        // 세로일때는 가로 방향, 가로일때는 세로 방향으로 만들도록 구현해야함.
        /*
        for (int i = dir * 2; i < dir + 2; ++i)
        {
            pos dg = { p.x + r_x[i], p.y + r_y[i] };

            if (dg.x < 0 || dg.x >= N || dg.y < 0 || dg.y >= N 
                || m_board[dg.x][dg.y] == 1)
            {
                continue;
            }

            push_if_ok(qq, p, i / 2, cnt + 1);
        }
        */
    }
    return -1;
}

int solution(vector<vector<int>> board) {

    m_board = board;
    N = board.size();

    return bfs();
}

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} };

    cout << solution(board);

    return 0;
}