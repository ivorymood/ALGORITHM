//https://programmers.co.kr/learn/courses/30/lessons/12952
//N-Queen
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int cnt;

void n_queen(vector<bool> &vrtc, vector<bool> &dgnl_1, vector<bool>& dgnl_2, int n, int y)
{
    // n퀸의 위치를 완성했을 때
    if (y == n)
    {
        ++cnt;
        return;
    }

    for (int x = 0; x < n; ++x)
    {
        /*
            [x]번째 세로열, [x + y]번째 우상향 대각선, [x - y + n - 1]번째 우하향 대각선에
            방문한 적이 없다면
        */
        if (!(vrtc[x] || dgnl_1[x + y] || dgnl_2[x - y + n - 1]))
        {
            vrtc[x] = dgnl_1[x + y] = dgnl_2[x - y + n - 1] = true;
            n_queen(vrtc, dgnl_1, dgnl_2, n, y + 1);
            vrtc[x] = dgnl_1[x + y] = dgnl_2[x - y + n - 1] = false;
        }
    }
}

int solution(int n) {

    vector<bool> vrtc(n);
    vector<bool> dgnl_1(2 * n - 1);
    vector<bool> dgnl_2(2 * n - 1);

    /*
        N-Queen이 같은 가로, 세로, 두 대각선을 방문하지 않도록 해야 한다.

        첫번째 행의 위치부터 결정해나가므로 bool벡터는 세로와 두 대각선만 있으면 된다.
    */
    n_queen(vrtc, dgnl_1, dgnl_2, n, 0);

    return cnt;
}

int main()
{
    int n = 5;

    cout << solution(n);

    return 0;
}