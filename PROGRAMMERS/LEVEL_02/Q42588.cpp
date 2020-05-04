//https://programmers.co.kr/learn/courses/30/lessons/42588
//ž
#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    
    // ����: �ڱ⺸�� �� ���� ž�� ���� ã�� ���� ž idx
    stack<int> s;

    vector<int> answer(heights.size(), 0);
    for (int i = 0; i < heights.size(); i++)
    {
        // ���� top ���� <= i ���� --> ���� pop
        while (!s.empty() && heights[s.top()] <= heights[i])
        {
            s.pop();
        }

        // ���� top ���� > i ���� --> �� ���� �Է�
        if (!s.empty() && heights[s.top()] > heights[i])
        {
            answer[i] = s.top() + 1;
        }
        
        s.push(i);
    }

    return answer;
}

int main()
{
    vector<int> heights = { 1,5,3,6,7,6,5 };
    /*
    vector<int> heights = { 3,9,9,3,5,7,2 };
    vector<int> heights = { 6,9,5,7,4 };
    */

    vector<int> rtn = solution(heights);
    for (int i = 0; i < rtn.size(); i++)
    {
        cout << rtn[i] << ", ";
    }

    return 0;
}