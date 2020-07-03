//https://programmers.co.kr/learn/courses/30/lessons/1836
//리틀 프렌즈 사천성
#include <iostream>

#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct pos {
    int x, y;
};

int M, N;
vector<string> m_board;
vector<vector<pos>> alpha_pos;
int dr_x[] = {0, 1, 0, -1};
int dr_y[] = {1, 0, -1, 0};

bool reachable(char c, pos from, pos to)
{
    // 4방향으로 가능한 끝까지 뻗어나가기
    for (int i = 0; i < 4; ++i)
    {
        int nx = from.x + dr_x[i];
        int ny = from.y + dr_y[i];
        while (!(nx < 0 || nx >= M || ny < 0 || ny >= N))
        {
            if (nx == to.x && ny == to.y)
            {
                return true;
            }
            if (m_board[nx][ny] != '.')
            {
                break;
            }
             
            // 위아래 -> 양옆, 양옆 -> 위아래
            // 방향이 겹치지 않게 2방향으로만 뻗어나가기
            for (int j = ((i + 1) % 2); j < 4; j += 2)
            {
                int nnx = nx + dr_x[j];
                int nny = ny + dr_y[j];

                while (!(nnx < 0 || nnx >= M || nny < 0 || nny >= N))
                {
                    if (nnx == to.x && nny == to.y)
                    {
                        return true;
                    }
                    if (m_board[nnx][nny] != '.')
                    {
                        break;
                    }

                    nnx += dr_x[j];
                    nny += dr_y[j];
                }
            }

            nx += dr_x[i];
            ny += dr_y[i];
        }
    }

    return false;
}

bool game(string &answer, int left)
{
    while (true)
    {
        bool match = false;

        // 알파벳 순으로 가장 먼저인 문자열을 출력해야한다
        for (int i = 0; i < 26; ++i)
        {
            // 맞춰야할 짝이 아직 남아있다면
            if (!alpha_pos[i].empty())
            {
                char c = i + 'A';
                pos from = alpha_pos[i][0];
                pos to = alpha_pos[i][1];

                // 두 알파벳이 1번 이하로 꺾어서 닿을 수 있다면
                if (reachable(c, from, to))
                {
                    // 답 문자열에 저장
                    answer += c;

                    // 알파벳이 있던 자리 빈칸처리, alpha_pos에 저장되어 있던 위치 비우기
                    m_board[from.x][from.y] = '.';
                    m_board[to.x][to.y] = '.';
                    alpha_pos[i].clear();
                    match = true;
                    left -= 2;
                    break;
                }
            }
        }

        if (!match)
        {
            break;
        }
    }
   
    // 모든 짝이 맞춰졌으면 true반환
    return (left == 0);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {

    // 전역변수 처리
    M = m;
    N = n;
    m_board = board;
    alpha_pos = vector<vector<pos>>(26);

    // 각 알파벳의 위치 2개 찾아 alpha_pos벡터에 저장
    int left = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (isalpha(board[i][j]))
            {
                // 총 알파벳 개수
                ++left;
                alpha_pos[board[i][j] - 'A'].push_back({ i, j });
            }
        }
    }

    // 짝을 모두 맞추는게 가능하면 순서 출력
    string answer = "";
    if (game(answer, left))
    {
        return answer;
    }

    // 불가능할 때
    return "IMPOSSIBLE";
}

int main()
{
    int m = 2; int n = 4; vector<string> board = { "NRYN", "ARYA" }; //RYAN
    /*
    int m = 2; int n = 2; vector<string> board = { "AB", "BA" }; //IMPOSSIBLE
    int m = 3; int n = 3; vector<string> board = { "DBA", "C*A", "CDB" }; //ABCD
    int m = 4; int n = 4; vector<string> board = { ".ZI.", "M.**", "MZU.", ".IU." }; //MUZI
    */

    cout << solution(m, n, board);

    return 0;
}