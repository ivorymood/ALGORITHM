//https://www.acmicpc.net/problem/2234
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template <typename T>
using d_vector = vector<vector<T>>;

int dr_y[] = {0, -1, 0, 1};
int dr_x[] = {-1, 0, 1, 0};
int N, M;
d_vector<int> castle;
d_vector<int> labeled_castle; // 방 번호(1부터 시작)를 라벨링할 2차원 배열
vector<int> sizes;            // 방의 크기를 저장

// 벽 1개를 허물었을 때 가장 큰 방의 크기 구하기
int get_max_integrated_room_size()
{
    int max_size = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 4방향 탐색
            for (int k = 0; k < 4; ++k)
            {
                int now_no = labeled_castle[i][j];
                int ny = i + dr_y[k];
                int nx = j + dr_x[k];

                if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                {
                    continue;
                }

                // 두 칸이 벽하나를 사이에 둔 다른 방일 때, 두방을 합친 크기로 최대값 갱신
                int next_no = labeled_castle[ny][nx];
                if (now_no != next_no && max_size < sizes[now_no] + sizes[next_no])
                {
                    max_size = sizes[now_no] + sizes[next_no];
                }
            }
        }
    }
    return max_size;
}

// bfs로 방 번호를 라벨링
void label_room(int i, int j, int num)
{
    // 큐에 첫번째 칸을 push 및 라벨링
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    labeled_castle[i][j] = num;
    ++sizes[num];

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 4방향 탐색
        for (int k = 0; k < 4; ++k)
        {
            // 벽이 없다면 다음 칸 진행
            if (((1 << k) & castle[y][x]) == 0)
            {
                int ny = y + dr_y[k];
                int nx = x + dr_x[k];
                if (ny < 0 || ny >= M || nx < 0 || nx >= N || labeled_castle[ny][nx] > 0)
                {
                    continue;
                }

                // labeled_castle에 방 번호를 매기고, sizes[방 번호]의 값을 + 1
                labeled_castle[ny][nx] = num;
                ++sizes[num];

                // 큐에 [ny, nx] push
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> N >> M;
    castle = d_vector<int>(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> castle[i][j];
        }
    }

    /*
        labeled_castle 2차원 배열
        : 벽으로 막혀있지 않은 하나의 방이면 같은 숫자로 라벨링
        
        sizes 1차원 배열
        : 한 방의 크기를 세어서 저장
    */
    labeled_castle = d_vector<int>(M, vector<int>(N));
    sizes = vector<int>(1);
    int num = 0;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 아직 라벨링 되지 않은 칸이면 bfs함수 호출
            if (labeled_castle[i][j] == 0)
            {
                sizes.push_back(0);
                label_room(i, j, ++num);
            }
        }
    }

    // 출력
    cout << sizes.size() - 1 << '\n';
    cout << *max_element(sizes.begin(), sizes.end()) << '\n';
    cout << get_max_integrated_room_size() << '\n';

    return 0;
}