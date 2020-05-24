//https://programmers.co.kr/learn/courses/30/lessons/17677
//���� Ŭ�����͸�
#include <iostream>

#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

// map�� set�� �α��ھ� ��� ����
void push_map_set(string str, unordered_map<int, int> &str_map, set<int> &s)
{
    int len = str.size() - 1;
    for (int i = 0; i < len; ++i)
    {
        if (isalpha(str[i]) && isalpha(str[i + 1]))
        {
            // 2������ ������ AA ~ ZZ �̹Ƿ�, �̸� 26���� ���� ��ȯ�Ͽ� map�� key�� ����
            int tmp = (str[i] - 'A') * 26 + (str[i + 1] - 'A');
            
            // �ش��ϴ� key�� 1�� ����
            str_map[tmp]++;

            // set�� key ����
            s.insert(tmp);
        }
    }
}

// ��ī�� ���絵 ���ϱ�
double get_jaccard_index(set<int> &s, unordered_map<int, int> &str1_map, unordered_map<int, int> &str2_map)
{
    int inter_cnt = 0;
    int union_cnt = 0;

    // set�� ����� ���(�� map �� key) ���� ��ŭ for�� ������
    for (auto iter = s.begin(); iter != s.end(); ++iter)
    {
        /*
            ������ ũ�� += �� ��� �� �� ���� �� or 0
            ������ ũ�� += �� ��� �� �� ū ��
        */
        inter_cnt += min(str1_map[*iter], str2_map[*iter]);
        union_cnt += max(str1_map[*iter], str2_map[*iter]);
    }

    return (union_cnt) ? (double)inter_cnt / union_cnt : 1;
}

// ���ڿ��� �빮�ڷ� ��ȯ
void make_upper(string &str)
{
    for (char &c : str)
    {
        c = toupper(c);
    }
}

int solution(string str1, string str2) {

    const int MLTF = 65536;

    // ���ڿ��� �빮�ڷ� ��ȯ
    make_upper(str1);
    make_upper(str2);

    unordered_map<int, int> str1_map, str2_map;
    set<int> s;

    // map�� set�� �α��ھ� ��� ����
    push_map_set(str1, str1_map, s);
    push_map_set(str2, str2_map, s);

    // ��ī�� ���絵 ���ϱ�
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