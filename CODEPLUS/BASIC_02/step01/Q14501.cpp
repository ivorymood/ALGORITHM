//https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>

using namespace std;

int max_sum;

void dfs(vector<int> &dates, vector<int> &money, int sum, int index)
{
	// ���� ���� ������ �־��� ��¥���� Ŭ��
	if (index > dates.size())
	{
		return;
	}
	// �־��� ��¥�� ���� ������ �� ���� ��
	else if (index == dates.size())
	{
		if (max_sum < sum)
		{
			max_sum = sum;
		}
		return;
	}

	// index�Ͽ� ���� �ϰ��� ������ ��
	dfs(dates, money, sum + money[index], index + dates[index]);

	// index�Ͽ� ���� �ϰ��� �������� ���� ��
	dfs(dates, money, sum, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;

	vector<int> dates(N);
	vector<int> money(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> dates[i] >> money[i];
	}
	
	// dfs - ��Ʈ��ŷ���� �ϰ� ����
	dfs(dates, money, 0, 0);

	cout << max_sum;

	return 0;
}