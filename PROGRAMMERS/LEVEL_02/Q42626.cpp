//https://programmers.co.kr/learn/courses/30/lessons/42626
//�� �ʰ�
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {

    // �ּ� ���� scoville ��� ��� 
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    // ���� �ּҰ��� K �̻��� �Ǹ�, ���� Ƚ�� ��ȯ
    int answer = 0;
    while (!pq.empty() && pq.top() < K)
    {
        // ���� ���� ��Ұ� 1���̰�, ��� ���� K �̸� �϶� : �Ұ���
        if (pq.size() == 1)
        {
            return -1;
        }

        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        pq.push(min1 + min2 * 2);
        ++answer;

    }

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 }; int K = 7;

    cout << solution(scoville, K);

    return 0;
}