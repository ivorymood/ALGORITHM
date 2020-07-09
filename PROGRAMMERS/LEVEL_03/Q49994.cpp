//https://programmers.co.kr/learn/courses/30/lessons/49994
//�湮 ����
#include <iostream>

#include <string>
#include <set>
#include <tuple>

using namespace std;

const int LEN = 11;

struct pos {
    int y, x;
};

// ������ġ���� ��ɾ��� �̵��Ͽ� ���� ��ġ ���ϱ�
pos get_next_pos(pos p, char c)
{
    int ny = p.y;
    int nx = p.x;

    if (c == 'U')
    {
        ny -= 1;
    }
    else if (c == 'D')
    {
        ny += 1;
    }
    else if (c == 'R')
    {
        nx += 1;
    }
    else if (c == 'L')
    {
        nx -= 1;
    }

    // ������ �Ѿ��
    if (nx < 0 || nx >= LEN || ny < 0 || ny >= LEN)
    {
        return { -1, -1 };
    }

    // ���� �� �϶�
    return { ny, nx };
}

int solution(string dirs) {

    // �̵��� ���� ������ set {��ġ, ��ġ}
    set<tuple<int, int, int, int>> s;
    pos now = { 5, 5 };

    // ��ɾ� Ž��
    int cnt = 0;
    for (char c : dirs)
    {
        // ���� ��ġ ���ϱ�
        pos next = get_next_pos(now, c);
        
        // ��ǥ����� ��踦 �Ѿ�� ��ɾ�� ����
        if (next.y < 0)
        {
            continue;
        }

        // ���ο� ���� ��
        if (s.find(make_tuple(now.y, now.x, next.y, next.x)) == s.end())
        {
            // A->B, B->A �Ѵ� set�� ���� �� ī����
            s.insert(make_tuple(now.y, now.x, next.y, next.x));
            s.insert(make_tuple(next.y, next.x, now.y, now.x));
            ++cnt;
        }

        // ������ġ = ������ġ
        now = next;
    }

    return cnt;
}

int main()
{
    /*
    string dirs = "ULURRDLLU";
    */
    string dirs = "LULLLLLLU";

    cout << solution(dirs);

    return 0;
}