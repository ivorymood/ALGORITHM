//https://programmers.co.kr/learn/courses/30/lessons/64064
//�ҷ� �����
#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> com_set;

void dfs(vector<vector<int>> &cands, set<int> &pick_ban, int depth)
{
    // �������� : depth�� ���� ���̵��� ������ ��
    if (depth == cands.size())
    {
        /*
            ���� ���̵� ����set�� ���� ��� �����
            ( setƯ���� ������������ ������̵� ����� ������� ex)1345 )
        */
        int pick_set = 0;
        for (auto iter = pick_ban.begin(); iter != pick_ban.end(); ++iter)
        {
            pick_set *= 10;
            pick_set += *iter;
        }

        /*
            ���� ���̵� ���� set�� insert
            : ������ ������ ������ �־��ٸ� ���õ� ��
        */
        com_set.insert(pick_set);
       
        return;
    }

    // depth��°�� ������̵� �ĺ����ڿ� Ž��
    for (int i = 0; i < cands[depth].size(); ++i)
    {
        /*
            pick_ban set�� �߰� ���� ���� ���ڶ�� 
            set�� �߰� ��, depth + 1�� ����Լ� ȣ��
        */
        int user = cands[depth][i] + 1;
        if (pick_ban.find(user) == pick_ban.end())
        {
            pick_ban.insert(user);
            dfs(cands, pick_ban, depth + 1);
            pick_ban.erase(user); 
        }
    }
}

// ���� ���̵� �ĺ����� Ȯ��
bool check_if_cand(string &ban, string &user)
{
    // ���̰� �ٸ��� ���� ���̵�X
    if (ban.size() != user.size())
    {
        return false;
    }

    /*
        ���� ���̵�� ���� ���̵��� �����ڸ� ���ڰ� ���� �ٸ��� (* ����)
        : ���� ���̵�X
    */
    for (int i = 0; i < ban.size(); ++i)
    {
        if (ban[i] != '*' && ban[i] != user[i])
        {
            return false;
        }
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {

    int ban_size = banned_id.size();
    int user_size = user_id.size();
    vector<vector<int>> cands(ban_size);

    for (int i = 0; i < ban_size; ++i)
    {
        for (int j = 0; j < user_size; ++j)
        {
            /*
                j��° ����� ���̵� i��° ���� ���̵� �� �� �ִٸ�
                i��° ������̵� �ĺ� ���ڿ��� j push
            */
            if (check_if_cand(banned_id[i], user_id[j]))
            {
                cands[i].push_back(j);
            }
        }
    }

    // ���̿켱 Ž���� ��Ʈ��ŷ���� �ߺ����� �ʴ� ������̵� ��� �����
    set<int> pick_ban;
    dfs(cands, pick_ban, 0);

    // ������ ���� ���̵� ��ϰ��� ��ȯ
    return com_set.size();
}

int main()
{
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" }; // 2
    vector<string> banned_id = { "fr*d*", "abc1**" };


    /*
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" }; // 2
    vector<string> banned_id = { "*rodo", "*rodo", "******" };
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" }; // 3
    vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };

    */

    cout << solution(user_id, banned_id);

    return 0;
}