//https://programmers.co.kr/learn/courses/30/lessons/42584
//주식가격 
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    // 주어진 벡터 길이의 answer 벡터 생성
    vector<int> answer(prices.size());

    // 아직 더 작은 값을 찾지 못한 idx의 스택
    stack<int> s;

    for (int i = 0; i < prices.size(); i++)
    {
        // 더 작은 값을 찾은 s.top은 answer벡터 입력 후 pop
        while (!s.empty() && prices[s.top()] > prices[i])
        {
        cout << "i : " << i << "  top : " << s.top() << endl;
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    // 스택에 남아있는 인덱스들 처리 = 끝까지 더 작은 값을 찾지 못함
    while (!s.empty())
    {
        answer[s.top()] = prices.size() - 1 - s.top();
        s.pop();
    }

    return answer;
}

int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };
  
    vector<int> ans = solution(prices);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }

    return 0;
}