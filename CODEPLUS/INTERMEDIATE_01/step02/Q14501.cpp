//https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 15;
int N;
int time[MAX];
int pay[MAX];
int max_sum[MAX];

int go(int day)
{
	// �Ұ����� �ٹ� �϶�
	if (day > N)
	{
		return -987654321;
	}
	// ������ �ٹ� �϶�
	if (day == N)
	{
		return 0;
	}
	// day�� �ִ밪�� �������� ��
	if (max_sum[day] > 0)
	{
		return max_sum[day];
	}

	// day�Ͽ� ���� ����� �ϴ� ���
	int sum1 = go(day + time[day]) + pay[day];
	
	// day�Ͽ� ���� ����� ���� �ʴ� ���
	int sum2 = go(day + 1);

	// max_sum[day]�� �ִ밪 ���� �� ����
	return max_sum[day] = max(sum1, sum2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> time[i] >> pay[i];
		max_sum[i] = -1;
	}

	// �ִ� ���� ���
	cout << go(0);

	return 0;
}