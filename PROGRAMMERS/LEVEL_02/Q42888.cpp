//https://programmers.co.kr/learn/courses/30/lessons/42888
//오픈채팅방
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

    // 입장 또는 변경일 때 id_map맵에 <uid, nick> 저장
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

    // 입장 또는 퇴장일 때 answer벡터에 nick + 메시지 저장
    vector<string> answer;
    for (string line : record)
    {
        stringstream ss(line);
        ss >> command;
        ss >> uid;

        if (command[0] == ENTER)
        {
            answer.push_back(id_map[uid] + "님이 들어왔습니다.");
        }
        else if (command[0] == LEAVE)
        {
            answer.push_back(id_map[uid] + "님이 나갔습니다.");
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