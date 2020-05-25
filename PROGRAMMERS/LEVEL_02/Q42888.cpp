//https://programmers.co.kr/learn/courses/30/lessons/42888
//����ä�ù�
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {

    const char ENTER = 'E', LEAVE = 'L', CHANGE = 'C';
    unordered_map<string, string> id_map;
    string command, uid, nick;

    // ���� �Ǵ� ������ �� id_map�ʿ� <uid, nick> ����
    for (string line : record)
    {
        stringstream ss(line);
        ss >> command;

        if (command[0] == ENTER || command[0] == CHANGE)
        {
            ss >> uid;
            ss >> nick;
        
            id_map[uid] = nick;
        }
    }

    // ���� �Ǵ� ������ �� answer���Ϳ� nick + �޽��� ����
    vector<string> answer;
    for (string line : record)
    {
        stringstream ss(line);
        ss >> command;
        ss >> uid;

        if (command[0] == ENTER)
        {
            answer.push_back(id_map[uid] + "���� ���Խ��ϴ�.");
        }
        else if (command[0] == LEAVE)
        {
            answer.push_back(id_map[uid] + "���� �������ϴ�.");
        }
    }

    return answer;
}

int main()
{
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> rtn = solution(record);
    cout << "answer : " << endl;
    for (string s : rtn)
    {
        cout << s << endl;
    }

    return 0;
}