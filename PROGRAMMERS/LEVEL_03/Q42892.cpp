//https://programmers.co.kr/learn/courses/30/lessons/42892
//�� ã�� ����
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int X_MAX = 100000;

struct node {
    int no;
    int x, y;
    int limit_L, limit_R;
};

// y��������, x�������� ���Լ�
struct compare {
    bool operator ()(const node& A, const node& B) const
    {
        if (A.y != B.y)
        {
            return A.y < B.y;
        }
        return A.x > B.x;
    }
};

// ������ȸ
void preorder(vector<vector<int>>& graph, vector<int>& res, int now)
{
    res.push_back(now);

    for (int child : graph[now])
    {
        preorder(graph, res, child);
    }
}

// ������ȸ
void postorder(vector<vector<int>>& graph, vector<int>& res, int now)
{
    for (int child : graph[now])
    {
        postorder(graph, res, child);
    }

    res.push_back(now);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    // y��������, x������������ ���ĵǴ� �켱���� ť�� ��ȣ�� x,y�� push
    priority_queue<node, vector<node>, compare> pq;
    for (int i = 0; i < nodeinfo.size(); ++i)
    {
        node nd = { i + 1, nodeinfo[i][0], nodeinfo[i][1], };
        pq.push(nd);
    }

    /*
        nodes : y���� �ִ� ��带 x������� ����
        graph : ������� ����Ʈ(graph[�θ���] : �ڽĳ��)
    */
    int root_level = pq.top().y;
    vector<vector<node>> nodes(root_level + 1, vector<node>());
    vector<vector<int>> graph(nodeinfo.size() + 1, vector<int>());

    // ��Ʈ ����� �ڽ� ���� ������ ������ �� root_level���� push
    node root = pq.top(); pq.pop();
    root.limit_L = -1;
    root.limit_R = X_MAX + 1;
    nodes[root_level].push_back(root);
    
    // ��Ʈ ��尡 �ִ� y�������� Ž��
    for (int i = root_level; i > 0; --i)
    {
        // i���� ������ �ִٸ� Ž��
        for (int j = 0; j < nodes[i].size(); ++j)
        {
            node& parent = nodes[i][j];

            // �켱���� ť�� ���� ��Ұ� parent�� ���� �ڽ� ������ �ش��Ѵٸ�
            if (!pq.empty() && parent.limit_L < pq.top().x && pq.top().x < parent.x)
            {
                // ���� �ڽ��� parent�� limit_L������ ũ��, x������ ���� �ڽ��� ���� �� �ִ�
                node child = pq.top(); pq.pop();
                child.limit_L = parent.limit_L;
                child.limit_R = parent.x;

                // �ڽ��� y���� �ڽĳ�� push �� �θ����� ��������Ʈ�� �ڽĳ�� push
                nodes[child.y].push_back(child);
                graph[parent.no].push_back(child.no);
            }

            // �켱���� ť�� ���� ��Ұ� parent�� ������ �ڽ� ������ �ش��Ѵٸ�
            if (!pq.empty() && parent.x < pq.top().x && pq.top().x < parent.limit_R)
            {
                // ������ �ڽ��� parent�� x������ ũ��, limit_R������ ���� �ڽ��� ���� �� �ִ�
                node child = pq.top(); pq.pop();
                child.limit_L = parent.x;
                child.limit_R = parent.limit_R;

                // �ڽ��� y���� �ڽĳ�� push �� �θ����� ��������Ʈ�� �ڽĳ�� push
                nodes[child.y].push_back(child);
                graph[parent.no].push_back(child.no);
            }
        }
    }

    // ������ȸ, ������ȸ �迭 �����
    vector<vector<int>> answer(2, vector<int>());
    preorder(graph, answer[0], root.no);
    postorder(graph, answer[1], root.no);

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = { {5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2} };


    vector<vector<int>> res = solution(nodeinfo);
    for (vector<int>& v : res)
    {
        for (int i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}