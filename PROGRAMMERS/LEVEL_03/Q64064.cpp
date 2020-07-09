//https://programmers.co.kr/learn/courses/30/lessons/64064
//불량 사용자
#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> com_set;

void dfs(vector<vector<int>> &cands, set<int> &pick_ban, int depth)
{
    // 종료조건 : depth가 제재 아이디목록 길이일 때
    if (depth == cands.size())
    {
        /*
            제재 아이디 조합set에 넣을 목록 만들기
            ( set특성상 오름차순으로 제재아이디 목록이 만들어짐 ex)1345 )
        */
        int pick_set = 0;
        for (auto iter = pick_ban.begin(); iter != pick_ban.end(); ++iter)
        {
            pick_set *= 10;
            pick_set += *iter;
        }

        /*
            제재 아이디 조합 set에 insert
            : 기존에 동일한 조합이 있었다면 무시될 것
        */
        com_set.insert(pick_set);
       
        return;
    }

    // depth번째의 제재아이디 후보숫자열 탐색
    for (int i = 0; i < cands[depth].size(); ++i)
    {
        /*
            pick_ban set에 추가 되지 않은 숫자라면 
            set에 추가 후, depth + 1로 재귀함수 호출
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

// 제재 아이디 후보인지 확인
bool check_if_cand(string &ban, string &user)
{
    // 길이가 다르면 제재 아이디X
    if (ban.size() != user.size())
    {
        return false;
    }

    /*
        제재 아이디와 유저 아이디의 같은자리 문자가 서로 다르면 (* 제외)
        : 제재 아이디X
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
                j번째 사용자 아이디가 i번째 제재 아이디가 될 수 있다면
                i번째 제재아이디 후보 숫자열에 j push
            */
            if (check_if_cand(banned_id[i], user_id[j]))
            {
                cands[i].push_back(j);
            }
        }
    }

    // 깊이우선 탐색과 백트랙킹으로 중복되지 않는 제재아이디 목록 만들기
    set<int> pick_ban;
    dfs(cands, pick_ban, 0);

    // 가능한 제재 아이디 목록개수 반환
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