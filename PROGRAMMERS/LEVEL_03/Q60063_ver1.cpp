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
    pos A, B;
};

int N;
int dr_x[] = { 0, 1, 0, -1 };
int dr_y[] = { 1, 0, -1, 0 };
map<pair<pair<int, int>, pair<int, int>>, int> visited;
vector<vector<int>> m_board;

bool check(pos A, pos B)
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

    if (visited[{ {A.x, A.y}, {B.x, B.y}}])
    {
        return false;
    }

    return true;
}

void push_if_ok(queue<pair<robot, int>> &q, pos A, pos B, int cnt)
{
    // 정합성 체크
    if (check(A, B))
    {
        q.push({ {A, B}, cnt + 1 });
        
        /*
            A - B 와 B - A는 같은 위치를 뜻한다
        */
        visited[{ { A.x, A.y }, { B.x, B.y }}] = 1;
        visited[{ { B.x, B.y }, { A.x, A.y }}] = 1;
    }
}

int bfs()
{
    queue<pair<robot, int>> q;
    q.push({ { {0, 0}, {0, 1} }, 0 });
    visited[{ {0, 0}, { 0, 1 } }] = 1;
    visited[{ {0, 1}, { 0, 0 } }] = 1;

    while (!q.empty())
    {
        robot &r = q.front().first;
        pos A = r.A;
        pos B = r.B;
        int cnt = q.front().second;
        q.pop();

        // [N][N]에 도착하면 이동횟수 반환
        if ((A.x == N - 1 && A.y == N - 1) || (B.x == N - 1 && B.y == N - 1))
        {
            return cnt;
        }

        // 4방향 이동
        for (int i = 0; i < 4; ++i)
        {
            pos nA = { A.x + dr_x[i], A.y + dr_y[i] };
            pos nB = { B.x + dr_x[i], B.y + dr_y[i] };

            push_if_ok(q, nA, nB, cnt);
        }

        // 회전
        {
            // 가로
            if (A.x == B.x)
            {
                // B고정 A회전
                pos nA;
                if (A.x - 1 >= 0 && m_board[A.x - 1][A.y] == 0)
                {
                    nA = { A.x - 1, A.y + 1 };
                    push_if_ok(q, nA, B, cnt);
                }
                if (A.x + 1 < N && m_board[A.x + 1][A.y] == 0)
                {
                    nA = { A.x + 1, A.y + 1 };
                    push_if_ok(q, B, nA, cnt);
                }

                // A고정 B회전
                pos nB;
                if (B.x - 1 >= 0 && m_board[B.x - 1][B.y] == 0)
                {
                    nB = {B.x - 1, B.y - 1};
                    push_if_ok(q, nB, A, cnt);
                }
                if (B.x + 1 < N && m_board[B.x + 1][B.y] == 0)
                {
                    nB = { B.x + 1, B.y - 1 };
                    push_if_ok(q, A, nB, cnt);
                }
            }
            // 세로
            else if (A.y == B.y)
            {
                // B고정 A회전
                pos nA;
                if (A.y - 1 >= 0 && m_board[A.x][A.y - 1] == 0)
                {
                    nA = { A.x + 1, A.y - 1 };
                    push_if_ok(q, nA, B, cnt);
                }
                if (A.y + 1 < N && m_board[A.x][A.y + 1] == 0)
                {
                    nA = { A.x + 1, A.y + 1 };
                    push_if_ok(q, B, nA, cnt);
                }

                // A고정 B회전
                pos nB;
                if (B.y - 1 >= 0 && m_board[B.x][B.y - 1] == 0)
                {
                    nB = { B.x - 1, B.y - 1 };
                    push_if_ok(q, nB, A, cnt);
                }
                if (B.y + 1 < N && m_board[B.x][B.y + 1] == 0)
                {
                    nB = { B.x - 1, B.y + 1 };
                    push_if_ok(q, A, nB, cnt);
                }
            }
        }
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
    vector<vector<int>> board = {{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}};

    cout << solution(board);

    return 0;
}