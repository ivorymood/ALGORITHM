//https://programmers.co.kr/learn/courses/30/lessons/1832
//������ õ��
#include <iostream>

#include <vector>

using namespace std;

int MOD = 20170805;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
    
    struct from{
        int to_right, to_down;
    };
    
    vector<vector<from>> way_map(m + 1, vector<from>(n + 1));
    way_map[0][1].to_down = 1;
    
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j) 
        {
            // ������ġ�� ���� ������ ��
            if (city_map[i - 1][j - 1] == 1)
            {
                continue;
            }

            /*
                ���� ��ġ�� = left �� + up ��  (= ���� ��ġ ������ ��)

                ���� ��ġ to_down = left.to_right + left.to_down
                ���� ��ġ to_right = left.to_right + left.to_down
            */
            from &up = way_map[i - 1][j];
            from &left = way_map[i][j - 1];
            
            int from_up = up.to_right + up.to_down;
            int from_left = left.to_right + left.to_down;
            
            /*
                ���� ��ġ (left / up)�� ��,��ȸ�� ������ ��
                ���� ������ ���� ������
            */
            if (i - 2 >= 0 && j - 1 >= 0 && city_map[i - 2][j - 1] == 2)
            {
                from_up = up.to_down;
            }
            if (i - 1 >= 0 && j - 2 >= 0 && city_map[i - 1][j - 2] == 2)
            {
                from_left = left.to_right;
            }


            way_map[i][j].to_right = from_left % MOD;
            way_map[i][j].to_down = from_up % MOD;
        }
    }

    // ������ ���� �հ� ��ȯ
    return (way_map[m][n].to_right + way_map[m][n].to_down) % MOD;
}

int main()
{

    int m = 3; int n = 6; vector<vector<int>> city_map = {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}; // 2
   /*
    int m = 3; int n = 3; vector<vector<int>> city_map = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; // 6
   */

    cout << solution(m, n, city_map);

    return 0;
}