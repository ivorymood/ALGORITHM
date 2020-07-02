//https://programmers.co.kr/learn/courses/30/lessons/60062
//외벽 점검
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {

    // 순열을 위해 dist정렬
    sort(dist.begin(), dist.end());

    int w_size = weak.size();
    int d_size = dist.size();
    int answer = -1;

    // 취약지점 파견을 시작하는 모든 경우의 수 구하기
    for (int i = 0; i < w_size; ++i)
    {
        /*
            한칸씩 앞으로 이동하고, 맨 앞칸은 맨 뒤로 보내기

            ex) 1 5 6 10  --> 5 6 10 13 
            마지막 13 = 1 + 12(n)
        */
        int tmp = weak[0] + n;
        for (int j = 1; j < w_size; ++j)
        {
            weak[j - 1] = weak[j];
        }
        weak[w_size - 1] = tmp;

        /*
            ex) n = 50, weak = [1, 5, 10, 16, 22, 25], dist = [3, 4, 6] 의 경우
                4:(1, 5),  6:(10, 16),  3:(22, 25) 만이 가능하다.
                
            따라서 dist벡터 내림차순 정열을 이용한 그리디기법은 사용할 수 없고 완전탐색이 필요하다
        */
        do {
            
            int w_idx = 0;
            int d_idx = 0;

            while (d_idx < d_size && w_idx < w_size)
            {
                // 친구가 최대로 닿을 수 있는 지점
                int end = weak[w_idx] + dist[d_idx];

                // 그 안에 있는 취약지점은 방문 완료 처리
                while (w_idx < w_size && weak[w_idx] <= end)
                {
                    ++w_idx;
                }
                ++d_idx;
            }

            // 모든 취약지점을 다 방문했을 때
            if (w_idx == w_size)
            {
                answer = (answer < 0) ? d_idx : min(d_idx, answer);
            }
        
        } while (next_permutation(dist.begin(), dist.end()));
    }

    return answer;
}

int main()
{
    /*
    int n = 12; vector<int> weak = {1, 5, 6, 10}; vector<int> dist = {1, 2, 3, 4};
    int n = 12; vector<int> weak = {1, 3, 4, 9, 10}; vector<int> dist = {3, 5, 7};
    int n = 50; vector<int> weak = {1}; vector<int> dist = {6};
    */
    int n = 50; vector<int> weak = { 1, 5, 10, 16, 22, 25 }; vector<int> dist = { 3, 4, 6 };

    cout << solution(n, weak, dist);

    return 0;
}