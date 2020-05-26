//https://programmers.co.kr/learn/courses/30/lessons/17686
//파일명 정렬
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 헤드, 숫자, 입력순서를 저장할 구조체
struct file_info {
    string head;
    int number;
    int index;
};

// 헤드, 숫자, 입력 순서 순으로 비교
bool compare(file_info first, file_info second)
{
    int order = first.head.compare(second.head);
    if (order != 0)
    {
        return order < 0;
    }
    if (first.number != second.number)
    {
        return first.number < second.number;
    }
    return first.index < second.index;
}

vector<string> solution(vector<string> files) {

    vector<file_info> infos;
    for (int i = 0; i < files.size(); ++i)
    {
        string file = files[i];

        // 헤드 만들기 (모두 대문자로)
        string head;
        int end = 0;
        while (!isdigit(file[end]))
        {
            file[end] = toupper(file[end]);
            ++end;
        }

        // 숫자 만들기
        int num = 0;
        while (isdigit(file[end]))
        {
            num *= 10;
            num += file[end] - '0';
            ++end;
        }

        // infos벡터에 헤드, 숫자, 입력순서 구조체 저장
        file_info f = { head, num, i };
        infos.push_back(f);
    }

    // 헤드, 숫자, 입력 순서 순으로 정렬
    sort(infos.begin(), infos.end(), compare);

    // answer벡터에 infos에서 정렬된 인덱스에 해당하는 file명 저장
    vector<string> answer;
    for (auto iter = infos.begin(); iter != infos.end(); ++iter)
    {
        answer.push_back(files[iter->index]);
    }

    return answer;
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