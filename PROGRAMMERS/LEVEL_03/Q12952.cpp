//https://programmers.co.kr/learn/courses/30/lessons/12952
//N-Queen
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int cnt;

void n_queen(vector<bool> &vrtc, vector<bool> &dgnl_1, vector<bool>& dgnl_2, int n, int y)
{
    // n���� ��ġ�� �ϼ����� ��
    if (y == n)
    {
        ++cnt;
        return;
    }

    for (int x = 0; x < n; ++x)
    {
        /*
            [x]��° ���ο�, [x + y]��° ����� �밢��, [x - y + n - 1]��° ������ �밢����
            �湮�� ���� ���ٸ�
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
        N-Queen�� ���� ����, ����, �� �밢���� �湮���� �ʵ��� �ؾ� �Ѵ�.

        ù��° ���� ��ġ���� �����س����Ƿ� bool���ʹ� ���ο� �� �밢���� ������ �ȴ�.
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