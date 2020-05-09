//https://programmers.co.kr/learn/courses/30/lessons/49993
//��ųƮ��
#include <iostream>

#include <string>
#include <vector>

using namespace std;

// �� ���ڿ��� ��ų ������ ������ ��ųƮ������ �˻�
bool possible(int input_order[], string &tree)
{
    int t_order = 1;
    for (int i = 0; i < tree.size(); ++i)
    {
        // ���ེų ��Ͽ� �־��� ��ų�� �˻�
        if (input_order[tree[i] - 'A'])
        {
            // ���ེų�� ������ �ٸ��� false ����
            if (input_order[tree[i] - 'A'] != t_order)
            {
                return false;
            }
            // ������ �ε��� ����
            ++t_order;
        }
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    
    // ���ེų�� �־��� ��ųƮ�� ���� �Է�
    const int MAX = 26;
    int input_order[MAX] = { 0, };
    int order = 1;
    for (int i = 0; i < skill.size(); ++i)
    {
        input_order[skill[i] - 'A'] = order++;
    }
    
    // �� ��ų Ʈ�� �˻�
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