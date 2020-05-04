//https://programmers.co.kr/learn/courses/30/lessons/42588
//탑
#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    
    // 스택: 자기보다 더 작은 탑을 아직 찾지 못한 탑 idx
    stack<int> s;

    vector<int> answer(heights.size(), 0);
    for (int i = 0; i < heights.size(); i++)
    {
        // 스택 top 높이 <= i 높이 --> 스택 pop
        while (!s.empty() && heights[s.top()] <= heights[i])
        {
            s.pop();
        }

        // 스택 top 높이 > i 높이 --> 답 벡터 입력
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