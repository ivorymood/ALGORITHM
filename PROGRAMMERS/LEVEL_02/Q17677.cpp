//https://programmers.co.kr/learn/courses/30/lessons/17677
//뉴스 클러스터링
#include <iostream>

#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

// map과 set에 두글자씩 끊어서 저장
void push_map_set(string str, unordered_map<int, int> &str_map, set<int> &s)
{
    int len = str.size() - 1;
    for (int i = 0; i < len; ++i)
    {
        if (isalpha(str[i]) && isalpha(str[i + 1]))
        {
            // 2글자의 범위가 AA ~ ZZ 이므로, 이를 26진법 수로 전환하여 map의 key로 저장
            int tmp = (str[i] - 'A') * 26 + (str[i + 1] - 'A');
            
            // 해당하는 key를 1씩 증가
            str_map[tmp]++;

            // set에 key 저장
            s.insert(tmp);
        }
    }
}

// 자카드 유사도 구하기
double get_jaccard_index(set<int> &s, unordered_map<int, int> &str1_map, unordered_map<int, int> &str2_map)
{
    int inter_cnt = 0;
    int union_cnt = 0;

    // set에 저장된 요소(두 map 의 key) 개수 만큼 for문 돌리기
    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        /*
            교집합 크기 += 두 요소 중 더 작은 값 or 0
            합집합 크기 += 두 요소 중 더 큰 값
        */
        inter_cnt += min(str1_map[*iter], str2_map[*iter]);
        union_cnt += max(str1_map[*iter], str2_map[*iter]);
    }

    return (union_cnt) ? (double)inter_cnt / union_cnt : 1;
}

// 문자열을 대문자로 전환
void make_upper(string &str)
{
    for (char &c : str)
    {
        c = toupper(c);
    }
}

int solution(string str1, string str2) {

    const int MLTF = 65536;

    // 문자열을 대문자로 전환
    make_upper(str1);
    make_upper(str2);

    unordered_map<int, int> str1_map, str2_map;
    set<int> s;

    // map과 set에 두글자씩 끊어서 저장
    push_map_set(str1, str1_map, s);
    push_map_set(str2, str2_map, s);

    // 자카드 유사도 구하기
    double answer = get_jaccard_index(s, str1_map, str2_map);
    return answer * MLTF;
}

int main()
{
    /*
    string str1 = "aa1+aa2";  string str2 = "AAAA12";
    string str1 = "handshake";  string str2 = "shake hands";
    string str1 = "E=M*C^2";  string str2 = "e=m*c^2";
    */
    string str1 = "FRANCE";  string str2 = "french";

    cout << solution(str1, str2);

    return 0;
}