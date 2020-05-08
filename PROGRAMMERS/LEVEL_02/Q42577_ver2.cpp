//https://programmers.co.kr/learn/courses/30/lessons/42577
//��ȭ��ȣ ���
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {

    // key : "��ȭ��ȣ�� �Ϻ�" , value : �󵵼�
    unordered_map<string, int> split_book;

    // ��� ��ȭ��ȣ�� �Ϻθ� �ؽøʿ� �����ϰ� �󵵼� ī��Ʈ
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

    // ��ȭ��ȣ�� �󵵼��� 1 �ʰ��̸� false����
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