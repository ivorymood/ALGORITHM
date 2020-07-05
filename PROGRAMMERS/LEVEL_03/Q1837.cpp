//https://programmers.co.kr/learn/courses/30/lessons/1837
//GPS
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {

    // ���� ����Ʈ ����
    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (int i = 0; i < m ; ++i)
    {
        int from = edge_list[i][0];
        int to = edge_list[i][1];

        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    // D[i][j] : i��° �αװ� j�� ��, i��° j�� ������� ���ľ� �ϴ� �α��� �ּ� Ƚ��
    vector<vector<int>> D(k, vector<int>(n + 1, INF));
    
    // ���۰�ο� �� ��δ� �����Ǿ� �ִ�.
    D[0][gps_log[0]] = 0;


    // gps_log�� 2��° �ڸ����� Ž��
    for (int i = 1; i < k; ++i)
    {
        // gps_log�� i��° �ڸ��� j�϶�, �ּ��� ��ģ Ƚ���� i - 1��° ���������� ��������
        for (int j = 1; j <= n; ++j)
        {
            // �̵����� �ʰ� �����Ͽ��� ���ڸ��� ������ �ִ� ���
            D[i][j] = min(D[i - 1][j], D[i][j]);

            // j�� ����� ���� ��忡�� j�� �̵��� ���
            for (int adj : adj_list[j])
            {
                D[i][j] = min(D[i - 1][adj], D[i][j]);
            }

            // �α׸� ���ƴٸ� Ƚ�� �����ֱ�
            D[i][j] += (gps_log[i] == j) ? 0 : 1;
        }
    }


    // �ùٸ� ��η� �����ϴ� ���� �Ұ����� ���
    if (D[k - 1][gps_log[k - 1]] >= INF)
    {
        return -1;
    }

    // �� ��η� ������� ���ľ� �ϴ� �α��� �ּ� Ƚ��
    return D[k - 1][gps_log[k - 1]];
}

int main()
{
    int n = 7; int m = 10; int k = 6;
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    vector<int> gps_log = {1, 2, 4, 6, 5, 7}; // 0

    /*
    int n = 7; int m = 10; int k = 6;
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    vector<int> gps_log = {1, 2, 3, 3, 6, 7}; // 1
    */

    cout << solution(n, m, edge_list, k, gps_log);

    return 0;
}