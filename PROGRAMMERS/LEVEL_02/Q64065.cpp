//https://programmers.co.kr/learn/courses/30/lessons/64065
//튜플
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

    // 각 집합을 v벡터로 변환하여, size가 작은 순서대로 t_vec에 저장
    for (int i = 1; i < s.size(); ++i)
    {
        // { : 숫자개수 및 v벡터 클리어
        if (s[i] == '{')
        {
            index = 0;
            v.clear();
        }
        // } : t_vec[숫자개수 - 1] 에 v벡터 저장
        else if (s[i] == '}')
        {
            t_vec[index - 1] = v;
            max_index = max(max_index, index);
        }
        // 숫자 : ','이나 '}'로 구분되는 숫자들을 v벡터에 저장
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

    // 저장한 집합의 개수만큼 t_vec 길이 재조정
    t_vec.resize(max_index);
}

vector<int> solution(string s) {
    
    const int MY_SIZE_MAX = 500;
    const int MY_NUM_MAX = 100000;
    
    vector<vector<int>> t_vec(MY_SIZE_MAX);
    
    // 입력 문자열 -> vector<vector<int>> 변환. 
    parse_input(s, t_vec);

    // size가 작은 집합의 숫자부터 반환vector에 저장
    vector<int> answer;
    bool check[MY_NUM_MAX + 1] = { 0, };
    for (vector<int> v : t_vec)
    {
        for (int i : v)
        {
            // 아직 저장하지 않은 숫자만 새로 저장
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