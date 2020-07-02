//https://programmers.co.kr/learn/courses/30/lessons/60062
//�ܺ� ����
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {

    // ������ ���� dist����
    sort(dist.begin(), dist.end());

    int w_size = weak.size();
    int d_size = dist.size();
    int answer = -1;

    // ������� �İ��� �����ϴ� ��� ����� �� ���ϱ�
    for (int i = 0; i < w_size; ++i)
    {
        /*
            ��ĭ�� ������ �̵��ϰ�, �� ��ĭ�� �� �ڷ� ������

            ex) 1 5 6 10  --> 5 6 10 13 
            ������ 13 = 1 + 12(n)
        */
        int tmp = weak[0] + n;
        for (int j = 1; j < w_size; ++j)
        {
            weak[j - 1] = weak[j];
        }
        weak[w_size - 1] = tmp;

        /*
            ex) n = 50, weak = [1, 5, 10, 16, 22, 25], dist = [3, 4, 6] �� ���
                4:(1, 5),  6:(10, 16),  3:(22, 25) ���� �����ϴ�.
                
            ���� dist���� �������� ������ �̿��� �׸������� ����� �� ���� ����Ž���� �ʿ��ϴ�
        */
        do {
            
            int w_idx = 0;
            int d_idx = 0;

            while (d_idx < d_size && w_idx < w_size)
            {
                // ģ���� �ִ�� ���� �� �ִ� ����
                int end = weak[w_idx] + dist[d_idx];

                // �� �ȿ� �ִ� ��������� �湮 �Ϸ� ó��
                while (w_idx < w_size && weak[w_idx] <= end)
                {
                    ++w_idx;
                }
                ++d_idx;
            }

            // ��� ��������� �� �湮���� ��
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