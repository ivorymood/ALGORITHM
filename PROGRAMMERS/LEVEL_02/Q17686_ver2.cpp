//https://programmers.co.kr/learn/courses/30/lessons/17686
//파일명 정렬
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자에서 등장하는 첫번째 숫자의 인덱스 구하기
int get_first_num_idx(string s)
{
    int idx = 0;
    while (!isdigit(s[idx]))
    {
        ++idx;
    }
    return idx;
}

// 문자 순서 비교 (오름차순) 
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

// 문자에서 주어진 인덱스부터 시작하는 숫자값 구하기
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

// 숫자 순서 비교 (오름차순)
bool num_cmp(string first, string second)
{
    int f_idx = get_first_num_idx(first);
    int s_idx = get_first_num_idx(second);

    return make_num(f_idx, first) < make_num(s_idx, second);
}

vector<string> solution(vector<string> files) {
    
    /*
        입력 순서를 유지해야 하므로 stable_sort로 안정 정렬
        head 순 정렬이 더 우선이기 때문에, 
        숫자 정렬을 먼저 하고 head정렬을 나중에 한다.
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