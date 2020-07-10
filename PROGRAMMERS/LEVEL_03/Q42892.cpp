//https://programmers.co.kr/learn/courses/30/lessons/42892
//길 찾기 게임
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

// y내림차순, x오름차순 비교함수
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

// 전위순회
void preorder(vector<vector<int>>& graph, vector<int>& res, int now)
{
    res.push_back(now);

    for (int child : graph[now])
    {
        preorder(graph, res, child);
    }
}

// 후위순회
void postorder(vector<vector<int>>& graph, vector<int>& res, int now)
{
    for (int child : graph[now])
    {
        postorder(graph, res, child);
    }

    res.push_back(now);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    // y내림차순, x오름차순으로 정렬되는 우선순위 큐에 번호와 x,y값 push
    priority_queue<node, vector<node>, compare> pq;
    for (int i = 0; i < nodeinfo.size(); ++i)
    {
        node nd = { i + 1, nodeinfo[i][0], nodeinfo[i][1], };
        pq.push(nd);
    }

    /*
        nodes : y층에 있는 노드를 x순서대로 저장
        graph : 인접노드 리스트(graph[부모노드] : 자식노드)
    */
    int root_level = pq.top().y;
    vector<vector<node>> nodes(root_level + 1, vector<node>());
    vector<vector<int>> graph(nodeinfo.size() + 1, vector<int>());

    // 루트 노드의 자식 제한 범위를 설정한 후 root_level층에 push
    node root = pq.top(); pq.pop();
    root.limit_L = -1;
    root.limit_R = X_MAX + 1;
    nodes[root_level].push_back(root);
    
    // 루트 노드가 있는 y레벨부터 탐색
    for (int i = root_level; i > 0; --i)
    {
        // i층에 노드들이 있다면 탐색
        for (int j = 0; j < nodes[i].size(); ++j)
        {
            node& parent = nodes[i][j];

            // 우선순위 큐의 다음 요소가 parent의 왼쪽 자식 범위에 해당한다면
            if (!pq.empty() && parent.limit_L < pq.top().x && pq.top().x < parent.x)
            {
                // 왼쪽 자식은 parent의 limit_L값보다 크고, x값보다 작은 자식을 가질 수 있다
                node child = pq.top(); pq.pop();
                child.limit_L = parent.limit_L;
                child.limit_R = parent.x;

                // 자식의 y층에 자식노드 push 및 부모노드의 인접리스트에 자식노드 push
                nodes[child.y].push_back(child);
                graph[parent.no].push_back(child.no);
            }

            // 우선순위 큐의 다음 요소가 parent의 오른쪽 자식 범위에 해당한다면
            if (!pq.empty() && parent.x < pq.top().x && pq.top().x < parent.limit_R)
            {
                // 오른쪽 자식은 parent의 x값보다 크고, limit_R값보다 작은 자식을 가질 수 있다
                node child = pq.top(); pq.pop();
                child.limit_L = parent.x;
                child.limit_R = parent.limit_R;

                // 자식의 y층에 자식노드 push 및 부모노드의 인접리스트에 자식노드 push
                nodes[child.y].push_back(child);
                graph[parent.no].push_back(child.no);
            }
        }
    }

    // 전위순회, 후위순회 배열 만들기
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