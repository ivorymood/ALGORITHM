//https://programmers.co.kr/learn/courses/30/lessons/1829
//카카오 프렌즈 컬러링북
#include <iostream>

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// bfs 풀이
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    // 오른쪽, 아래쪽, 왼쪽, 위쪽
    vector<pair<int, int>> drx = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    vector<int> cnt;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // 색칠된 "새로운" 영역이 있으면 같은 색 영역 탐색 시작
            if (!visited[i][j] && picture[i][j] > 0)
            {
                cnt.push_back(0);
                q.push(make_pair(i, j));
                visited[i][j] = true;

                while (!q.empty())
                {
                    // 이번 차례 영역값 저장 후 queue.pop
                    int x = q.front().first;
                    int y = q.front().second;
                    int num = picture[x][y];
                    
                    q.pop();
                    printf("x : %d  y : %d   color : %d\n", x, y, num);

                    // 해당 색 영역 개수 + 1
                    ++* (cnt.end() - 1);

                    // 색이 같은 인접 영역을 4 방향으로 탐색 
                    for (int k = 0; k < 4; ++k)
                    {
                        int newX = x + drx[k].first;
                        int newY = y + drx[k].second;

                        // 아직 방문하지 않고, 색이 같은 인접영역을 찾으면 queue에 push
                        if (newX >= 0 && newX < m && newY >= 0 && newY < n 
                            && !visited[newX][newY] && num == picture[newX][newY])
                        {
                            q.push(make_pair(newX, newY));
                            visited[newX][newY] = true;
                        }
                    }
                }
            }
        }
    }

    vector<int> answer(2);
    answer[0] = cnt.size();
    answer[1] = *max_element(cnt.begin(), cnt.end());

    return answer;
}

int main()
{
    /*

 

    

    vector<vector<int>> picture = { {1, 1, 1, 0},
                                    {1, 2, 2, 0},
                                    {1, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 3},
                                    {0, 0, 0, 3} };
  
    int m = 6;
    int n = 4;


    vector<vector<int>> picture = { {1, 1, 1, 0},
                                    {1, 1, 1, 0},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 1},
                                    {0, 0, 0, 1} };
  */


    int m = 13;
    int n = 16;
    vector<vector<int>> picture = { {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
                                    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                    { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
                                    { 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0 },
                                    { 0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0 },
                                    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
                                    { 0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0 },
                                    { 0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0 },
                                    { 0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0 },
                                    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
                                    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } };
    vector<int> res = solution(m, n, picture);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << ' ';
    }

    return 0;
}