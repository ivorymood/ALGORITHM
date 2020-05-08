//https://programmers.co.kr/learn/courses/30/lessons/42577
//전화번호 목록
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

    int len = phone_book.size();

    // 사전순 오름차순 정렬
    sort(phone_book.begin(), phone_book.end());

    // 앞 번호 전체와 뒷번호 일부분 비교
    for (int i = 0; i < len - 1; ++i)
    {
        if (phone_book[i + 1].compare(0, phone_book[i].size(), phone_book[i]) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<string> phone_book = { "12","123","1235","567","88" };
    /*
    vector<string> phone_book = { "123","456","789" };
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    */

    cout << solution(phone_book);

    return 0;
}