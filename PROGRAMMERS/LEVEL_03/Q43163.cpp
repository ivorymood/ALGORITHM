//https://programmers.co.kr/learn/courses/30/lessons/43163
//단어 변환
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 두 단어의 글자 차이가 1개 나면 true 반환
bool possible(string A, string B)
{
    int dif = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] != B[i])
        {
            ++dif;
        }
    }
    return dif == 1;
}

int bfs(string begin, string target, vector<string> words, int N)
{
    vector<bool> visited(N);
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while (!q.empty())
    {
        string now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 목표단어에 도착하면 이동횟수 리턴
        if (now == target)
        {
            return cnt;
        }

        // words벡터의 단어들 중 현재 단어와 글자가 1개 차이나고, 
        // 아직 방문한적 없으면 큐에 push
        for (int i = 0; i < N; ++i)
        {
            if (!visited[i] && possible(now, words[i]))
            {
                visited[i] = true;
                q.push({ words[i], cnt + 1 });
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {

    // bfs탐색으로 begin부터 target까지 최소 이동횟수 구하기
    return bfs(begin, target, words, words.size());
}

int main()
{
    /*
    string begin = "hit"; string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };

    */
    string begin = "hit"; string target = "cog"; 
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution(begin, target, words);

    return 0;
}