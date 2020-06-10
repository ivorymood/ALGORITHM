//https://www.acmicpc.net/problem/14225
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 * 20;

void dfs(vector<int>& nums, vector<bool> &visit, int num, int idx)
{
	// �κм����� �հ� num �湮üũ �ϱ�
	visit[num] = true;
	
	// �ε��� ������ ������ ����
	if (idx == nums.size())
	{
		return;
	}
	
	// idx��° ���� �������� �ʴ� ���
	dfs(nums, visit, num, idx + 1);

	// idx��° ���� �����ϴ� ���
	dfs(nums, visit, num + nums[idx], idx + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> nums[i];
	}

	// ��Ʈ��ŷ���� ������ �κ������� �� ��� ���ϱ�
	vector<bool> visit(MAX + 1);
	dfs(nums, visit, 0, 0);
	
	// �湮 üũ ���� ���� �� ���
	for (int i = 1; i <= MAX; ++i)
	{
		if (!visit[i])
		{
			cout << i << '\n';
			break;
		}
	}

	return 0;
}