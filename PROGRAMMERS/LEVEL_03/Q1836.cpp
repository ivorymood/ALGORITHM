//https://programmers.co.kr/learn/courses/30/lessons/1836
//��Ʋ ������ ��õ��
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
    // 4�������� ������ ������ �������
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
             
            // ���Ʒ� -> �翷, �翷 -> ���Ʒ�
            // ������ ��ġ�� �ʰ� 2�������θ� �������
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

        // ���ĺ� ������ ���� ������ ���ڿ��� ����ؾ��Ѵ�
        for (int i = 0; i < 26; ++i)
        {
            // ������� ¦�� ���� �����ִٸ�
            if (!alpha_pos[i].empty())
            {
                char c = i + 'A';
                pos from = alpha_pos[i][0];
                pos to = alpha_pos[i][1];

                // �� ���ĺ��� 1�� ���Ϸ� ��� ���� �� �ִٸ�
                if (reachable(c, from, to))
                {
                    // �� ���ڿ��� ����
                    answer += c;

                    // ���ĺ��� �ִ� �ڸ� ��ĭó��, alpha_pos�� ����Ǿ� �ִ� ��ġ ����
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
   
    // ��� ¦�� ���������� true��ȯ
    return (left == 0);
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(int m, int n, vector<string> board) {

    // �������� ó��
    M = m;
    N = n;
    m_board = board;
    alpha_pos = vector<vector<pos>>(26);

    // �� ���ĺ��� ��ġ 2�� ã�� alpha_pos���Ϳ� ����
    int left = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (isalpha(board[i][j]))
            {
                // �� ���ĺ� ����
                ++left;
                alpha_pos[board[i][j] - 'A'].push_back({ i, j });
            }
        }
    }

    // ¦�� ��� ���ߴ°� �����ϸ� ���� ���
    string answer = "";
    if (game(answer, left))
    {
        return answer;
    }

    // �Ұ����� ��
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