//https://programmers.co.kr/learn/courses/30/lessons/42890
//후보키
#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check_minimality(const vector<int> &keys, const int bit)
{
    // 현재 속성 집합이 기존의 후보키를 포함하면 false반환
    for (int i = 0; i < keys.size(); ++i)
    {
        if ((keys[i] & bit) == keys[i])
        {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {

    vector<int> keys;
    int cnt = 0;
    int tpl_len = relation.size();
    int clmn_len = relation[0].size();

    // 후보키 속성 구성을 비트마스크 순열로 조합하기
    for (int bit = 1; bit < (1 << clmn_len); ++bit)
    {
        // 최소성 만족 여부 검사
        if (!check_minimality(keys, bit))
        {
            continue;
        }

        // 유일성 만족 여부 검사
        unordered_set<string> set;
        for (int i = 0; i < tpl_len; ++i)
        {
            string key;
            for (int j = 0; j < clmn_len; ++j)
            {
                // 현재 속성 집합에 해당하는 value를 이어붙여서 set에 push하기
                if (bit & (1 << j))
                {
                    key += relation[i][j] + ' ';    // 속성간 구분자 추가
                }
            }
            set.insert(key);
        }

        // 중복되는 튜플이 없으면 후보키 벡터에 push, 카운팅
        if (set.size() == tpl_len)
        {
            keys.push_back(bit);
            ++cnt;
        }
    }
    
    return cnt;
}

int main()
{
    vector<vector<string>> relation = { {"100","ryan","music","2"},{"200","apeach","math","2"},
                                        {"300","tube","computer","3"},{"400","con","computer","4"},
                                        {"500","muzi","music","3"},{"600","apeach","music","2"} };

    cout << solution(relation);

    return 0;
}