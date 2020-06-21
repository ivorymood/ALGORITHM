//https://programmers.co.kr/learn/courses/30/lessons/43163
//�ܾ� ��ȯ
#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

// �� �ܾ��� ���� ���̰� 1�� ���� true ��ȯ
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

        // ��ǥ�ܾ �����ϸ� �̵�Ƚ�� ����
        if (now == target)
        {
            return cnt;
        }

        // words������ �ܾ�� �� ���� �ܾ�� ���ڰ� 1�� ���̳���, 
        // ���� �湮���� ������ ť�� push
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

    // bfsŽ������ begin���� target���� �ּ� �̵�Ƚ�� ���ϱ�
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