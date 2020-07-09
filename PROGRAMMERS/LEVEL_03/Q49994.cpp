//https://programmers.co.kr/learn/courses/30/lessons/49994
//방문 길이
#include <iostream>

#include <string>
#include <set>
#include <tuple>

using namespace std;

const int LEN = 11;

struct pos {
    int y, x;
};

// 현재위치에서 명령어대로 이동하여 다음 위치 구하기
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

    // 범위를 넘어서면
    if (nx < 0 || nx >= LEN || ny < 0 || ny >= LEN)
    {
        return { -1, -1 };
    }

    // 범위 내 일때
    return { ny, nx };
}

int solution(string dirs) {

    // 이동한 길을 저장할 set {위치, 위치}
    set<tuple<int, int, int, int>> s;
    pos now = { 5, 5 };

    // 명령어 탐색
    int cnt = 0;
    for (char c : dirs)
    {
        // 다음 위치 구하기
        pos next = get_next_pos(now, c);
        
        // 좌표평면의 경계를 넘어서는 명령어는 무시
        if (next.y < 0)
        {
            continue;
        }

        // 새로운 길일 때
        if (s.find(make_tuple(now.y, now.x, next.y, next.x)) == s.end())
        {
            // A->B, B->A 둘다 set에 저장 후 카운팅
            s.insert(make_tuple(now.y, now.x, next.y, next.x));
            s.insert(make_tuple(next.y, next.x, now.y, now.x));
            ++cnt;
        }

        // 현재위치 = 다음위치
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