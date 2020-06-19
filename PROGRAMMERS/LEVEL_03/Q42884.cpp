//https://programmers.co.kr/learn/courses/30/lessons/42884
//�ܼ�ī�޶�
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {

    // ������ �������� �������� ����
    sort(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
        });
    
    /*
        ī�޶� ��ġ�ϴ� ����
        : ���س���(std_end)�� �������� ���������� ���� �� (=������ ��ġ�� ���� ��)
        ���س����� ī�޶� ��ġ�Ѵ�.
    */

    // ���� ī�޶� ������ ���� ���� end��
    int std_end = routes[0][1];
    int camera = 0;

    for (int i = 0; i < routes.size(); ++i)
    {
        // std_end���� ���� ���� ������ ��ġ�� �ʴ´ٸ�
        if (std_end < routes[i][0])
        {
            ++camera;
            std_end = routes[i][1];
        }
    }
   
    // ������ end���� ī�޶� ��ġ
    return camera + 1;
}

int main()
{
    /*
    vector<vector<int>> routes = { {-20, 15}, {-14,-5}, {-18,-13}, {-5,-3} }; //2
    vector<vector<int>> routes = { {0,12} ,{1,12},  {2,12},{3,12},{5,6},{6,12},{10,12} }; //2
    vector<vector<int>> routes = { {-2,-1} ,{1,2},{-3,0} };//2
    vector<vector<int>> routes = { {0,0} };//1
    vector<vector<int>> routes = { {0,1} ,{0,1},{1,2} };//1
    vector<vector<int>> routes = { {0,1} ,{2,3},{4,5},{6,7} };//4
    vector<vector<int>> routes = { {-20,15}, {-14,-5}, {-18,-13}, {-5,-3}} };//2
    vector<vector<int>> routes = { {-20,15}, {-20,-15}, {-14,-5}, {-18,-13}, {-5,-3} };//2
    vector<vector<int>> routes = { {-7,0}, {-6,-4}, {-5,-3}, {-3,-1}, {-1,4}, {1,2}, {3,4} };//4
    vector<vector<int>> routes = { {-5,-3}, {-4,0}, {-4,-2}, {-1, 2}, {0,3}, {1,5}, {2,4}  };//2
    vector<vector<int>> routes = { {0,1}, {1,2}, {2,3} ,{3,4}, {5,4}, {5,6}, {6,7} , {8,7}, {8,9} ,{9,10}, {10,11}, {11,12}, {12,13}, {13,14} , {14,15}};//8
   */

    vector<vector<int>> routes = { {-20,-15}, {-14,-5}, {-18,-13}, {-5,-3} };//2

    cout << solution(routes);

    return 0;
}