//https://programmers.co.kr/learn/courses/30/lessons/12927
//�߱� ����
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {

    // �켱 ���� ť�� works ��� ����
    priority_queue<int, vector<int>, less<int>> pq;
    int sum = 0;
    for (int i : works)
    {
        pq.push(i);
        sum += i;
    }

    // ��ü ���� �۾������� n�� ���ų� ũ�ٸ� 0 ��ȯ
    if (sum <= n)
    {
        return 0;
    }

    // n�ð� ���� ���� ū �۾����� 1�� ó��
    while (n--)
    {
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp - 1);
    }

    // �߱� �Ƿε� ���
    long long answer = 0;
    while (!pq.empty())
    {
        answer += (long long)pq.top() * pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{
    /*
    int n = 4; vector<int> works = { 4, 3, 3 };
    int n = 1; vector<int> works = { 2, 1, 2 };
    */
    int n = 3; vector<int> works = { 1,1 };

    cout << solution(n, works);

    return 0;
}