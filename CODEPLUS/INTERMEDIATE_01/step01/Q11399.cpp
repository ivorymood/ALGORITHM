//https://www.acmicpc.net/problem/11399
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> times(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> times[i];
	}

	// �������� ����
	sort(times.begin(), times.end());

	// ������ ��ٸ� �ð� ���� ���ϱ�
	int total = 0, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += times[i];
		total += sum;
	}

	cout << total;

	return 0;
}