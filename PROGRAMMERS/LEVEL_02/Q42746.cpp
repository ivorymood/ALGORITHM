//https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp
//가장 큰 수
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {

    // 숫자 벡터 -> 문자열 벡터
    vector<string> str_nums(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
    {
        str_nums[i] = to_string(numbers[i]);
    }

    // 두 수를 이어붙였을 때를 가정하여 내림차순으로 정렬
    sort(str_nums.begin(), str_nums.end(), compare);

    // 모두 0일때 예외처리
    if (*str_nums.begin() == "0")
    {
        return "0";
    }

    // 모두 이어붙이기
    string answer = "";
    for (auto iter = str_nums.begin(); iter < str_nums.end(); iter++)
    {
        answer.append(*iter);
    }
    return answer;
}

int main()
{
    /*
    vector<int> numbers = { 6, 10, 2 };
    vector<int> numbers = { 3, 30, 32, 33, 34, 5, 9 };
    vector<int> numbers = {40, 403 };
    */
    vector<int> numbers = {70, 0, 0};

    cout << solution(numbers);

    return 0;
}