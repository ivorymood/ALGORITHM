//https://programmers.co.kr/learn/courses/30/lessons/17683
//방금그곡
#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 차이시간 구하기
int difftime(string start, string end)
{
    int hour_dif = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
    int min_dif = stoi(end.substr(3, 2)) - stoi(start.substr(3, 2));

    return 60 * hour_dif + min_dif;
}

// 샾노트 -> 소문자로 변경
void transform_sharp(string &sheet)
{
    int idx = 0, sheet_len = sheet.size();
    string n_sheet;
    while (idx < sheet_len)
    {
        if (sheet[idx + 1] == '#')
        {
            n_sheet += sheet[idx] + ('a' - 'A');
            idx += 2;
        }
        else
        {
            n_sheet += sheet[idx];
            idx += 1;
        }
    }
    sheet = n_sheet;
}

string solution(string m, vector<string> musicinfos) {

    // 들은노래 : 샾노트 -> 소문자로 변경
    transform_sharp(m);

    int max_time = 0;
    string music_name = "(None)";

    for (string line : musicinfos)
    {
        // 시작시각, 종료시각, 노래제목, 악보 파싱
        stringstream ss(line);
        string start, end, name, sheet;
        getline(ss, start, ',');
        getline(ss, end, ',');
        getline(ss, name, ',');
        getline(ss, sheet, ' ');

        // 악보 : 샾노트 -> 소문자로 변경
        transform_sharp(sheet);
        
        // 재생된 시간 구하기
        int time = difftime(start, end);
        int sheet_len = sheet.size();
        int full = time / sheet_len;
        int part = time % sheet_len;

        // 재생된 시간만큼 재생된 노래 문자열 만들기
        string new_sheet = "";
        for (int i = 0; i < full; ++i)
        {
            new_sheet += sheet;
        }
        new_sheet += sheet.substr(0, part);

        // 재생된 노래가 들은 노래 m을 포함하고, 재생시간이 max_time보다 클때 노래제목 저장
        if (new_sheet.find(m) != string::npos && max_time < time)
        {
            max_time = time;
            music_name = name;
        }
    }

    return music_name;
}

int main()
{
    /*
    string m = "ABC"; vector<string> musicinfos = { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    string m = "ABC"; vector<string> musicinfos = { "12:00,12:09,HELLO,ABC#ABC#ABC" };
    string m = "ABCDEFG"; vector<string> musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    */
    string m = "CC#BCC#BCC#BCC#B"; vector<string> musicinfos = { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" };

    cout << solution(m, musicinfos);

    return 0;
}