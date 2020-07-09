//https://programmers.co.kr/learn/courses/30/lessons/64062
//¡�˴ٸ� �ǳʱ�
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200000000;

bool check(vector<int> &stones, int k, int passed)
{
    // ���� ������ ����
    int last_idx = -1;
    for (int i = 0; i < stones.size(); ++i)
    {
        // �ǳ� �� �ִ� ������̸�
        if (stones[i] - passed >= 0)
        {
            // ������ ��������� ������ k�ʰ��̸� false
            if (i - last_idx > k)
            {
                return false;
            }
            last_idx = i;
        }
    }

    // ������ �������� �Ÿ��� k���ϸ� true
    return (stones.size() - last_idx <= k);
}

int solution(vector<int> stones, int k) {

    // stones ��� �� �ּҰ�/�ִ밪 ���ϱ�
    int left = MAX;
    int right = 0;
    for (int stone : stones)
    {
        left = min(stone, left);
        right = max(stone, right);
    }

    /*
        �̺�Ž��
        ������ �����ϴ� ����� ���� �� �ִ밪 ���ϱ�
    */
    int answer = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(stones, k, mid))
        {
            answer = max(mid, answer);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }; int k = 3;

    cout << solution(stones, k);

    return 0;
}