//https://programmers.co.kr/learn/courses/30/lessons/12977
//�Ҽ� �����
#include <iostream>
#include <vector>
using namespace std;

int cnt;

// �Ҽ� �Ǻ�
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(vector<int> &nums, int sum, int N, int depth, int start)
{
    // N���� ���ڸ� ���� sum�� �Ҽ����� �Ǻ��ϰ� ī��Ʈ
    if (depth == N)
    {
        if (is_prime(sum))
        {
            ++cnt;
        }
        return;
    }

    // ���� �ٸ� N���� ���ڸ� ���ؾ��ϹǷ�,
    // ���� depth�� ���� �ڸ� ���ں��� for�� ������
    for (int i = start; i < nums.size(); ++i)
    {
        dfs(nums, sum + nums[i], N, depth + 1, i + 1);
    }
}

int solution(vector<int> nums) {
    
    const int pick = 3;
    dfs(nums, 0, pick, 0, 0);

    return cnt;
}

int main()
{
    /*
    vector<int> nums = { 1,2,3,4 };
    */
    vector<int> nums = { 1,2,7,6,4 };

    cout << solution(nums);

    return 0;
}