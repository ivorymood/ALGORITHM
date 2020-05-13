//https://programmers.co.kr/learn/courses/30/lessons/42629
//라면공장
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {

    // 최대 힙 선언(우선순위 큐)
    priority_queue<int, vector<int>, less<int>> pq;
    
    int cnt = 0;
    int strt = 0;

    // stock : 버틸 수 있는 날짜. stock의 숫자에 해당하는 날까지 버틸 수 있다.
    // 즉, stock은 결국 k 만큼 있어야 한다.
    while (stock < k)
    {
        /*
            큐 : "버틸 수 있는 날짜까지" 선택 가능한 공급들.
            ex) 4일에는 10일에 들어오는 공급을 선택할 수 없다.

            push한 이후에는 중복해서 큐에 넣지 않도록, strt 인덱스를 증가시켜 준다.
        */
        for (int i = strt; i < dates.size() && dates[i] <= stock; ++i)
        {
            pq.push(supplies[i]);
            ++strt;
        }
            
        // 최소 공급 횟수를 위해 최대 공급양부터 선택한다.
        stock += pq.top();
        pq.pop();
        ++cnt;
    }

    return cnt;
}

int main()
{
    /*
    int stock = 4;
    vector<int> dates = { 1, 2, 3, 4 };
    vector<int> supplies = { 1, 1, 1, 1 };
    int k = 6;
    */

    int stock = 4;  
    vector<int> dates = { 4,10,15 };
    vector<int> supplies = { 20,5,10 };
    int k = 30;

    cout << solution(stock, dates, supplies, k);

    return 0;
}