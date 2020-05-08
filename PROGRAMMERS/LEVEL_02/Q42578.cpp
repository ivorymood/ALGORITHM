//https://programmers.co.kr/learn/courses/30/lessons/42578?language=cpp
//����
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    // key: ���� ���� , value : ����
    unordered_map<string, int> cloth_kind;

    for (int i = 0; i < clothes.size(); ++i)
    {
        ++cloth_kind[clothes[i][1]];
    }

    // ������ �� ���� ���� + 1(���Դ� ����� ��) �� ��� ���Ѵ���,
    // �ƹ��͵� ���Դ� ��� 1������ ����.
    int cnt = 1;
    for (auto iter = cloth_kind.begin(); iter != cloth_kind.end(); ++iter)
    {
        cnt *= iter->second + 1;
    }

    return cnt - 1;
}

int main()
{
    vector<vector<string>> clothes = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };
    /*
    vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };
    */

    cout << solution(clothes);

    return 0;
}