//https://programmers.co.kr/learn/courses/30/lessons/43165
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int cnt;

void dfs(const vector<int> &numbers, int sum, int i, const int &target)
{
    if (i == numbers.size())
    {
        if (sum == target)
        {
            cnt++;
        }
        return ;
    }

    dfs(numbers, sum + numbers[i], i + 1, target);
    
    dfs(numbers, sum - numbers[i], i + 1, target);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, 0, 0, target);

    return cnt;
}

int main()
{
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target = 3;

    cout << solution(numbers, target);

    return 0;
}   