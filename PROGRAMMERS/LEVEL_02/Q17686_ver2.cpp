//https://programmers.co.kr/learn/courses/30/lessons/17686
//���ϸ� ����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���ڿ��� �����ϴ� ù��° ������ �ε��� ���ϱ�
int get_first_num_idx(string s)
{
    int idx = 0;
    while (!isdigit(s[idx]))
    {
        ++idx;
    }
    return idx;
}

// ���� ���� �� (��������) 
bool head_cmp(string first, string second)
{
    int first_num = get_first_num_idx(first);
    int second_num = get_first_num_idx(second);

    string f_string = first.substr(0, first_num);
    string s_string = second.substr(0, second_num);

    transform(f_string.begin(), f_string.end(), f_string.begin(), ::toupper);
    transform(s_string.begin(), s_string.end(), s_string.begin(), ::toupper);

    int order = f_string.compare(s_string);
    return order < 0;
}

// ���ڿ��� �־��� �ε������� �����ϴ� ���ڰ� ���ϱ�
int make_num(int idx, string s)
{
    int num = 0;
    while (idx < s.size() && isdigit(s[idx]))
    {
        num *= 10;
        num += s[idx] - '0';
        ++idx;
    }
    return num;
}

// ���� ���� �� (��������)
bool num_cmp(string first, string second)
{
    int f_idx = get_first_num_idx(first);
    int s_idx = get_first_num_idx(second);

    return make_num(f_idx, first) < make_num(s_idx, second);
}

vector<string> solution(vector<string> files) {
    
    /*
        �Է� ������ �����ؾ� �ϹǷ� stable_sort�� ���� ����
        head �� ������ �� �켱�̱� ������, 
        ���� ������ ���� �ϰ� head������ ���߿� �Ѵ�.
    */
    stable_sort(files.begin(), files.end(), num_cmp);
    stable_sort(files.begin(), files.end(), head_cmp);

    return files;
}

int main()
{
    /*
    vector<string> files = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};
    */
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };

    vector<string> rtn = solution(files);

    cout << "answer : " << endl;
    for (string s : rtn)
    {
        cout << s << endl;
    }

    return 0;
}