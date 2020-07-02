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

    // 원형탐색을 위해 weak벡터 뒤쪽에 각 요소보다 n씩 큰 요소 추가
    for (int i = 0; i < w_size; ++i)
    {
        weak.push_back(weak[i] + n);
    }

    // 원형탐색: w_idx부터 탐색 시작
    for (int w_idx = 0; w_idx < w_size; ++w_idx)
    {
        /*
            ex) n = 50, weak = [1, 5, 10, 16, 22, 25], dist = [3, 4, 6] 의 경우
                4:(1, 5),  6:(10, 16),  3:(22, 25) 만이 가능하다.
                
            따라서 dist벡터 내림차순 정열을 이용한 그리디기법은 사용할 수 없고 완전탐색이 필요하다
        */
        do {
            
            int passed = 0;
            int d_idx = 0;

            // weak과 dist의 인덱스가 범위 하에 있으면
            while (d_idx < d_size && passed < w_size)
            {
                // 친구가 최대로 닿을 수 있는 지점
                int end = weak[w_idx + passed] + dist[d_idx];

                // 그 사이에 있는 취약지점은 방문 완료 처리
                while (passed < w_size && weak[w_idx + passed] <= end)
                {
                    ++passed;
                }
                ++d_idx;
            }

            // 모든 취약지점을 다 방문했을 때 : 가장 적은 파견 친구수 갱신
            if (passed == w_size)
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