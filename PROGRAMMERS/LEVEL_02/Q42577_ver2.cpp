//https://programmers.co.kr/learn/courses/30/lessons/42577
//전화번호 목록
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {

    // key : "전화번호의 일부" , value : 빈도수
    unordered_map<string, int> split_book;

    // 모든 전화번호의 일부를 해시맵에 저장하고 빈도수 카운트
    int len = phone_book.size();
    for (int i = 0; i < len; ++i)
    {
        string number = "";
        for (int j = 0; j < phone_book[i].size(); ++j)
        {
            number += phone_book[i][j];
            ++split_book[number];
        }
    }

    // 전화번호의 빈도수가 1 초과이면 false리턴
    for (int i = 0; i < len; ++i)
    {
        if (split_book[phone_book[i]] > 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    /*
    vector<string> phone_book = { "12","123","1235","567","88" };
    vector<string> phone_book = { "123","456","789" };
    */

    cout << solution(phone_book);

    return 0;
}