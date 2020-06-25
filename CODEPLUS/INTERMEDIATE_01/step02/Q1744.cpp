//https://www.acmicpc.net/problem/1744
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tie_n_get_sum(vector<int> &v)
{
	int len = v.size();
	long long res = 0;

	for (int i = 0; i < len; ++i)
	{
		// �������� +1�� �ƴϸ� : ������� �������� ���ؼ� ���Ѵ�
		if (i + 1 < len && v[i + 1] != 1)
		{
			res += v[i] * v[i + 1];
			++i;
		}
		// �������� ������ : ������� ���Ѵ�
		else
		{
			res += v[i];
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<int> minus;
	vector<int> plus;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		// 0 �ʰ��� ���� plus���Ϳ� ���
		if (num > 0)
		{
			plus.push_back(num);
		}
		// 0 ������ ���� minus���Ϳ� ���
		else
		{
			minus.push_back(num);
		}
	}

	// minus���ʹ� ��������, plus���ʹ� �������� ����
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end(), [](int A, int B) {
		
		return A > B;
		});
	
	/*
		������ ���͸� ������ ���� ���� �ִ��� ���� ���ϱ�
		
		������ ��������, ����� ������� �������Ƿ�
		������ �� +���� �����Ѵ�.
	*/
	cout << (tie_n_get_sum(minus) + tie_n_get_sum(plus));

	return 0;
}