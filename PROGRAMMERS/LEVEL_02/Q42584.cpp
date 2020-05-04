//https://programmers.co.kr/learn/courses/30/lessons/42584
//�ֽİ��� 
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    // �־��� ���� ������ answer ���� ����
    vector<int> answer(prices.size());

    // ���� �� ���� ���� ã�� ���� idx�� ����
    stack<int> s;

    for (int i = 0; i < prices.size(); i++)
    {
        // �� ���� ���� ã�� s.top�� answer���� �Է� �� pop
        while (!s.empty() && prices[s.top()] > prices[i])
        {
        cout << "i : " << i << "  top : " << s.top() << endl;
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    // ���ÿ� �����ִ� �ε����� ó�� = ������ �� ���� ���� ã�� ����
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