//https://programmers.co.kr/learn/courses/30/lessons/49993
//스킬트리
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 각 문자열의 스킬 순서가 가능한 스킬트리인지 검사
bool possible(int input_order[], string &tree)
{
    int t_order = 1;
    for (int i = 0; i < tree.size(); ++i)
    {
        // 선행스킬 목록에 주어진 스킬만 검사
        if (input_order[tree[i] - 'A'])
        {
            // 선행스킬과 순서가 다르면 false 리턴
            if (input_order[tree[i] - 'A'] != t_order)
            {
                return false;
            }
            // 같으면 인덱스 증가
            ++t_order;
        }
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    
    // 선행스킬로 주어진 스킬트리 순서 입력
    const int MAX = 26;
    int input_order[MAX] = { 0, };
    int order = 1;
    for (int i = 0; i < skill.size(); ++i)
    {
        input_order[skill[i] - 'A'] = order++;
    }
    
    // 각 스킬 트리 검사
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        if (possible(input_order, skill_trees[i]))
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };

    cout << solution(skill, skill_trees);

    return 0;
}