//https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp
//���� ū ��
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

    // ���� ���� -> ���ڿ� ����
    vector<string> str_nums(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
    {
        str_nums[i] = to_string(numbers[i]);
    }

    // �� ���� �̾�ٿ��� ���� �����Ͽ� ������������ ����
    sort(str_nums.begin(), str_nums.end(), compare);

    // ��� 0�϶� ����ó��
    if (*str_nums.begin() == "0")
    {
        return "0";
    }

    // ��� �̾���̱�
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