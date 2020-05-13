//https://programmers.co.kr/learn/courses/30/lessons/42629
//������
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {

    // �ִ� �� ����(�켱���� ť)
    priority_queue<int, vector<int>, less<int>> pq;
    
    int cnt = 0;
    int strt = 0;

    // stock : ��ƿ �� �ִ� ��¥. stock�� ���ڿ� �ش��ϴ� ������ ��ƿ �� �ִ�.
    // ��, stock�� �ᱹ k ��ŭ �־�� �Ѵ�.
    while (stock < k)
    {
        /*
            ť : "��ƿ �� �ִ� ��¥����" ���� ������ ���޵�.
            ex) 4�Ͽ��� 10�Ͽ� ������ ������ ������ �� ����.

            push�� ���Ŀ��� �ߺ��ؼ� ť�� ���� �ʵ���, strt �ε����� �������� �ش�.
        */
        for (int i = strt; i < dates.size() && dates[i] <= stock; ++i)
        {
            pq.push(supplies[i]);
            ++strt;
        }
            
        // �ּ� ���� Ƚ���� ���� �ִ� ���޾���� �����Ѵ�.
        stock += pq.top();
        pq.pop();
        ++cnt;
    }

    return cnt;
}

int main()
{
    /*
    int stock = 4;
    vector<int> dates = { 1, 2, 3, 4 };
    vector<int> supplies = { 1, 1, 1, 1 };
    int k = 6;
    */

    int stock = 4;  
    vector<int> dates = { 4,10,15 };
    vector<int> supplies = { 20,5,10 };
    int k = 30;

    cout << solution(stock, dates, supplies, k);

    return 0;
}