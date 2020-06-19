//https://programmers.co.kr/learn/courses/30/lessons/42861
//�� �����ϱ�
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���x�� ���Ե� Ʈ���� ��Ʈ��� ��������
int get_root(vector<int> &parent, int x)
{
    // x�� ���x�� �θ���
    if (x == parent[x])
    {
        return x;
    }
    
    /*
        �ٸ� ��尡 ���x�� �θ���,
        ��Ʈ��带 ã�� ������ ����Լ� ȣ��.
        
        �������� ���x�� �θ� �ش� ��Ʈ��� ������ ��ȯ
    */
    return parent[x] = get_root(parent, parent[x]);
}

// Ʈ�� ��ġ��
void union_parent(vector<int>& parent, int a, int b)
{
    /*
        �� ��� a, b�� ���Ե� Ʈ���� ��Ʈ��� ���ڸ� ���Ͽ�
        �� ���� ������ ��Ʈ��� Ʈ���� ����
    */
    a = get_root(parent, a);
    b = get_root(parent, b);
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

// ���� ������ Ʈ���� ���ԵǾ� �ִ��� ���� Ȯ��
bool find_parent(vector<int>& parent, int a, int b)
{
    a = get_root(parent, a);
    b = get_root(parent, b);
    
    return (a == b);
}

int solution(int n, vector<vector<int>> costs) {

    // costs : [from, to, cost]������ ����� 2���� ����
    // ����� �������� �������� ����
    sort(costs.begin(), costs.end()
        , [&costs](vector<int> &a, vector<int> &b) 
        {
            return a[2] < b[2];
        }
    );

    // ��� ����� �θ� �ڱ��ڽ����� �ʱ� ����
    vector<int> parent(n);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    // �ּҺ������ ��� ���� �����ϴ� �ٸ� �Ǽ��ϱ�
    int sum = 0;
    for (int i = 0; i < costs.size(); ++i)
    {
        // �� ����� �Ҽ� Ʈ���� �ٸ��ٸ�
        if (!find_parent(parent, costs[i][0], costs[i][1]))
        {
            // �ٸ� �Ǽ�
            sum += costs[i][2];
            
            // ���� Ʈ���� ���Խ�Ű��
            union_parent(parent, costs[i][0], costs[i][1]);
        }
    }

    return sum;
}

int main()
{
    /*
    int n = 5;
    vector<vector<int>> costs = { {0,1,1} ,{0,2,2},{1,2,5},{1,3,3},{2,3,8}, {3,4,1} };

    int n = 4;
    vector<vector<int>> costs = { {0, 1, 5} ,{1,2,3},{2,3,3},{3,1,2},{3,0,4} };
    */

    int n = 4;
    vector<vector<int>> costs = { {0,1,1} ,{0,2,2},{1,2,5},{1,3,1},{2,3,8} };
    
    cout << solution(n, costs);

    return 0;
}