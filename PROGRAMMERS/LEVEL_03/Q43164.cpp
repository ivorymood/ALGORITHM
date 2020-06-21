//https://programmers.co.kr/learn/courses/30/lessons/43164
//������
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
    // ���� Ƽ�� ������ ������ ����
    if (left == 0)
    {
        return true;
    }

    // ���� ������ ��������Ʈ Ž�� �� ��Ʈ��ŷ
    for (airport &to : t_map[now])
    {
        if (to.passed == false)
        {
            to.passed = true;
            order.push_back(to.port);
            // �ѹ��̶� ��� ������ �� ���Ҵٸ� ����
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

    // �������� ��θ� ���� ticket���͸� �������� ����
    sort(tickets.begin(), tickets.end());

    // ���� ����Ʈ �����
    map<string, vector<airport>> t_map;
    for (vector<string> ticket : tickets)
    {
        t_map[ticket[0]].push_back({ ticket[1], false });
    }
    
    // �׻� ICN���� ���
    vector<string> order;
    order.push_back("ICN");

    // dfs�� ������ ��θ� Ž���Ͽ� order���Ϳ� �����ϱ�
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