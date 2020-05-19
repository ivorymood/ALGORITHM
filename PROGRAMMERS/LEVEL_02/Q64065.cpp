//https://programmers.co.kr/learn/courses/30/lessons/64065
//Ʃ��
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void parse_input(string &s, vector<vector<int>> &t_vec)
{
    vector<int> v;
    int index = 0;
    int max_index = 0;

    // �� ������ v���ͷ� ��ȯ�Ͽ�, size�� ���� ������� t_vec�� ����
    for (int i = 1; i < s.size(); ++i)
    {
        // { : ���ڰ��� �� v���� Ŭ����
        if (s[i] == '{')
        {
            index = 0;
            v.clear();
        }
        // } : t_vec[���ڰ��� - 1] �� v���� ����
        else if (s[i] == '}')
        {
            t_vec[index - 1] = v;
            max_index = max(max_index, index);
        }
        // ���� : ','�̳� '}'�� ���еǴ� ���ڵ��� v���Ϳ� ����
        else if (s[i] >= '0' && s[i] <= '9')
        {
            int num = s[i] - '0';
            ++i;
            while (!(s[i] == ',' || s[i] == '}'))
            {
                num *= 10;
                num += s[i] - '0';
                ++i;
            }
            v.push_back(num);
            ++index;
            --i;
        }
    }

    // ������ ������ ������ŭ t_vec ���� ������
    t_vec.resize(max_index);
}

vector<int> solution(string s) {
    
    const int MY_SIZE_MAX = 500;
    const int MY_NUM_MAX = 100000;
    
    vector<vector<int>> t_vec(MY_SIZE_MAX);
    
    // �Է� ���ڿ� -> vector<vector<int>> ��ȯ. 
    parse_input(s, t_vec);

    // size�� ���� ������ ���ں��� ��ȯvector�� ����
    vector<int> answer;
    bool check[MY_NUM_MAX + 1] = { 0, };
    for (vector<int> v : t_vec)
    {
        for (int i : v)
        {
            // ���� �������� ���� ���ڸ� ���� ����
            if (!check[i])
            {
                answer.push_back(i);
                check[i] = true;
            }
        }
    }

    return answer;
}

int main()
{
    /*
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    string s = "{{20,111},{111}}";
    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    string s = "{{123}}";
    */
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";

    vector<int> result = solution(s);
    cout << "======================" << endl;
    for (int i : result)
    {
        cout << i << endl;
    }

    return 0;
}