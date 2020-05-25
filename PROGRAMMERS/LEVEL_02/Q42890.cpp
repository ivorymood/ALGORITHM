//https://programmers.co.kr/learn/courses/30/lessons/42890
//�ĺ�Ű
#include <iostream>

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check_minimality(const vector<int> &keys, const int bit)
{
    // ���� �Ӽ� ������ ������ �ĺ�Ű�� �����ϸ� false��ȯ
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

    // �ĺ�Ű �Ӽ� ������ ��Ʈ����ũ ������ �����ϱ�
    for (int bit = 1; bit < (1 << clmn_len); ++bit)
    {
        // �ּҼ� ���� ���� �˻�
        if (!check_minimality(keys, bit))
        {
            continue;
        }

        // ���ϼ� ���� ���� �˻�
        unordered_set<string> set;
        for (int i = 0; i < tpl_len; ++i)
        {
            string key;
            for (int j = 0; j < clmn_len; ++j)
            {
                // ���� �Ӽ� ���տ� �ش��ϴ� value�� �̾�ٿ��� set�� push�ϱ�
                if (bit & (1 << j))
                {
                    key += relation[i][j] + ' ';    // �Ӽ��� ������ �߰�
                }
            }
            set.insert(key);
        }

        // �ߺ��Ǵ� Ʃ���� ������ �ĺ�Ű ���Ϳ� push, ī����
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