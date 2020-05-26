//https://programmers.co.kr/learn/courses/30/lessons/17686
//���ϸ� ����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���, ����, �Է¼����� ������ ����ü
struct file_info {
    string head;
    int number;
    int index;
};

// ���, ����, �Է� ���� ������ ��
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

        // ��� ����� (��� �빮�ڷ�)
        string head;
        int end = 0;
        while (!isdigit(file[end]))
        {
            file[end] = toupper(file[end]);
            ++end;
        }

        // ���� �����
        int num = 0;
        while (isdigit(file[end]))
        {
            num *= 10;
            num += file[end] - '0';
            ++end;
        }

        // infos���Ϳ� ���, ����, �Է¼��� ����ü ����
        file_info f = { head, num, i };
        infos.push_back(f);
    }

    // ���, ����, �Է� ���� ������ ����
    sort(infos.begin(), infos.end(), compare);

    // answer���Ϳ� infos���� ���ĵ� �ε����� �ش��ϴ� file�� ����
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