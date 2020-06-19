//https://programmers.co.kr/learn/courses/30/lessons/42861
//섬 연결하기
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 노드x가 포함된 트리의 루트노드 가져오기
int get_root(vector<int> &parent, int x)
{
    // x가 노드x의 부모라면
    if (x == parent[x])
    {
        return x;
    }
    
    /*
        다른 노드가 노드x의 부모라면,
        루트노드를 찾을 때까지 재귀함수 호출.
        
        마지막에 노드x의 부모에 해당 루트노드 저장후 반환
    */
    return parent[x] = get_root(parent, parent[x]);
}

// 트리 합치기
void union_parent(vector<int>& parent, int a, int b)
{
    /*
        두 노드 a, b가 포함된 트리의 루트노드 숫자를 비교하여
        더 적은 숫자의 루트노드 트리로 편입
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

// 서로 동일한 트리에 포함되어 있는지 여부 확인
bool find_parent(vector<int>& parent, int a, int b)
{
    a = get_root(parent, a);
    b = get_root(parent, b);
    
    return (a == b);
}

int solution(int n, vector<vector<int>> costs) {

    // costs : [from, to, cost]순으로 저장된 2차원 벡터
    // 비용을 기준으로 오름차순 정렬
    sort(costs.begin(), costs.end()
        , [&costs](vector<int> &a, vector<int> &b) 
        {
            return a[2] < b[2];
        }
    );

    // 모든 노드의 부모를 자기자신으로 초기 세팅
    vector<int> parent(n);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    // 최소비용으로 모든 섬을 연결하는 다리 건설하기
    int sum = 0;
    for (int i = 0; i < costs.size(); ++i)
    {
        // 두 노드의 소속 트리가 다르다면
        if (!find_parent(parent, costs[i][0], costs[i][1]))
        {
            // 다리 건설
            sum += costs[i][2];
            
            // 한쪽 트리로 편입시키기
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