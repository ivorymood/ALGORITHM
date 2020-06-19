//https://programmers.co.kr/learn/courses/30/lessons/42628
//이중우선순위큐
#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {

    vector<int> datas;

    for (string line : operations)
    {
        // 명령어, 숫자 받아오기
        stringstream ss(line);
        char op;
        int num;
        ss >> op >> num;

        // 삽입 명령어
        if (op == 'I')
        {
            datas.push_back(num);
        }
        // 삭제 명령어이고 데이터가 남아있다면
        else if(datas.size() > 0)
        {
            // 최대값 삭제 : 가장 앞에 있는 값 삭제
            if (num > 0)
            {
                datas.erase(datas.begin());
            }
            // 최소값 삭제 : 가장 뒤에 있는 값 삭제
            else
            {
                datas.pop_back();
            }
        }

        // 내림차순 정렬
        sort(datas.begin(), datas.end(), [](int a, int b) {
            return a > b;
            });
    }
    
    // 시작인덱스 == 끝 인덱스 : 남은 데이터가 없다
    if (datas.size() == 0)
    {
        return { 0, 0 };
    }

    // 최대값, 최소값 반환
    return { *datas.begin(), *(datas.end() - 1) };
}

int main()
{
    /*
    vector<string> operations = { "I 7","I 5","I -5","D -1" };
    vector<string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };
    vector<string> operations = { "I 16","D 1" };
    */
    vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };

    vector<int> res =  solution(operations);
    for (int i : res)
    {
        cout << i << ' ';
    }

    return 0;
}