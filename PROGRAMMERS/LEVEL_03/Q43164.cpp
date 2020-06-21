//https://programmers.co.kr/learn/courses/30/lessons/43164
//여행경로
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct airport{
    string port;
    bool passed;
};

bool dfs(map<string, vector<airport>> &t_map, vector<string> &order, string now, int left)
{
    // 남은 티켓 개수가 없으면 종료
    if (left == 0)
    {
        return true;
    }

    // 현재 공항의 인접리스트 탐색 및 백트랙킹
    for (airport &to : t_map[now])
    {
        if (to.passed == false)
        {
            to.passed = true;
            order.push_back(to.port);
            // 한번이라도 모든 공항을 다 돌았다면 종료
            if (dfs(t_map, order, to.port, left - 1))
            {
                return true;
            }
            order.pop_back();
            to.passed = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {

    // 오름차순 경로를 위해 ticket벡터를 오름차순 정렬
    sort(tickets.begin(), tickets.end());

    // 인접 리스트 만들기
    map<string, vector<airport>> t_map;
    for (vector<string> ticket : tickets)
    {
        t_map[ticket[0]].push_back({ ticket[1], false });
    }
    
    // 항상 ICN에서 출발
    vector<string> order;
    order.push_back("ICN");

    // dfs로 가능한 경로를 탐색하여 order벡터에 저장하기
    dfs(t_map, order, "ICN", tickets.size());

    return order;
}

int main()
{
    /*
    vector<vector<string>> tickets = { {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };
    */
    vector<vector<string>> tickets = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} };

    vector<string> res = solution(tickets);
    for (string s : res)
    {
        cout << s << ' ';
    }

    return 0;
}