//https://www.acmicpc.net/problem/2751
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &v, int left, int right)
{
	int pl = left;
	int pr = right;
	int x = v[(pl + pr) / 2];	// �ǹ��� : L�ε����� R�ε����� �߾ӿ� �ִ� ��

	/*
		�ǹ����� �߽����� L�ε����� ���� R�ε����� ���� ��ȯ
		L�ε����� R�ε������� Ŀ���� �ݺ��� ����
	*/
	do {
		while (v[pl] < x) ++pl;
		while (v[pr] > x) --pr;
	
		if (pl <= pr)
		{
			swap(v[pl], v[pr]);
			++pl;
			--pr;
		}
	} while (pl <= pr);

	// ����Լ� ȣ��� �� ���� �κп� ���Ͽ� �Ȱ��� ���İ��� ����
	if (left < pr)
	{
		quick_sort(v, left, pr);
	}
	if (pl < right)
	{
		quick_sort(v, pl, right);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	// �� ����
	quick_sort(v, 0, N - 1);

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << v[i] << '\n';
	}

	return 0;
}