//https://programmers.co.kr/learn/courses/30/lessons/42583
//�ٸ��� ������ Ʈ�� 
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    queue<int> q;
    vector<int> pos(truck_weights.size());
    int sum_weight = 0, idx = 0, tm = 0;

    while (!q.empty() || idx < truck_weights.size())
    {
        tm++;
        if (!q.empty())
        {
            // ��ġ �̵�
            for (int i = q.front(); i <= q.back(); i++)
            {
                pos[i]++;
            }

            // �ٸ� �ٱ����� ���ö�
            if (pos[q.front()] >= bridge_length)
            {
                sum_weight -= truck_weights[q.front()];
                q.pop();
            }
        }

        // �ٸ��� Ʈ�� ���� + �̹� Ʈ�� ���� <= weight
        if (idx < truck_weights.size() && sum_weight + truck_weights[idx] <= weight)
        {
            sum_weight += truck_weights[idx];
            q.push(idx);
            idx++;
        }
    }

    return tm;
}

int main()
{
    /*
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = { 10 };
    
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = { 10,10,10,10,10,10,10,10,10,10 };
    */
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7,4,5,6 };

    cout << solution(bridge_length, weight, truck_weights);

    return 0;
}