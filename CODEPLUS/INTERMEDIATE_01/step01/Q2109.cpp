//https://www.acmicpc.net/problem/2109
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct lec {
	int d_day, pay;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	int today = 0;
	vector<lec> lectures(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> lectures[i].pay >> lectures[i].d_day;
		today = max(lectures[i].d_day, today);
	}

	// ��¥ ������������ �������� ����
	sort(lectures.begin(), lectures.end(), [](lec &A, lec &B) {
		return A.d_day > B.d_day;
		});


	int sum = 0;
	int l_idx = 0;
	priority_queue<int> q;

	// 1. ���� ������ ������ ������ ������ �����س�����.
	while (today)
	{
		// 2. d_day�� ������ ���Ǵ� �켱���� ť(���ð����� ������)�� push�Ѵ�
		while (l_idx < N && lectures[l_idx].d_day == today)
		{
			q.push(lectures[l_idx++].pay);
		}

		// 3. ť�� top�� ���ð����� ���� pay�� ���� �����̹Ƿ�, �����ϰ� pop�Ѵ�.
		if (!q.empty())
		{
			sum += q.top();
			q.pop();
		}
		
		--today;
	}

	cout << sum;

	return 0;
}