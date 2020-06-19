//https://programmers.co.kr/learn/courses/30/lessons/42628
//���߿켱����ť
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
        // ��ɾ�, ���� �޾ƿ���
        stringstream ss(line);
        char op;
        int num;
        ss >> op >> num;

        // ���� ��ɾ�
        if (op == 'I')
        {
            datas.push_back(num);
        }
        // ���� ��ɾ��̰� �����Ͱ� �����ִٸ�
        else if(datas.size() > 0)
        {
            // �ִ밪 ���� : ���� �տ� �ִ� �� ����
            if (num > 0)
            {
                datas.erase(datas.begin());
            }
            // �ּҰ� ���� : ���� �ڿ� �ִ� �� ����
            else
            {
                datas.pop_back();
            }
        }

        // �������� ����
        sort(datas.begin(), datas.end(), [](int a, int b) {
            return a > b;
            });
    }
    
    // �����ε��� == �� �ε��� : ���� �����Ͱ� ����
    if (datas.size() == 0)
    {
        return { 0, 0 };
    }

    // �ִ밪, �ּҰ� ��ȯ
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