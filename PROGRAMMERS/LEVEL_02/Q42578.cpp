//https://programmers.co.kr/learn/courses/30/lessons/42578?language=cpp
//위장
#include <iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    // key: 옷의 종류 , value : 개수
    unordered_map<string, int> cloth_kind;

    for (int i = 0; i < clothes.size(); ++i)
    {
        ++cloth_kind[clothes[i][1]];
    }

    // 각각의 옷 종류 개수 + 1(안입는 경우의 수) 를 모두 곱한다음,
    // 아무것도 안입는 경우 1가지를 뺀다.
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