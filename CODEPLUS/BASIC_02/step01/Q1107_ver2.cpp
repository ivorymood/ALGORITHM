//https://www.acmicpc.net/problem/1107
// ������ �����ؾ� �ϴ� Ǯ���Դϴ�.
// BOJ ä���� ��Ÿ�ӿ���

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int cnt;

void perm(const string& numbers, string output, int depth, int r)
{
	if (depth == r)
	{
		// ��ǥ ä�κ��� 1�ڸ� ���� �� ~ 1�ڸ� ���� �� üũ
		for (int i = 0; i < 3; i++)
		{
			if (r - i >= 0)
			{
				int res = stoi(output.substr(0, r - i));
				
				// ��ư ���� �� Ƚ�� : ���� ����� ä�� ���� + (+/-) ��ư ���� Ƚ��
				if (cnt > abs(res - N) + to_string(res).size())
				{
					cnt = abs(res - N) + to_string(res).size();
				}
			}
		}

		return;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		perm(numbers, output + numbers[i], depth + 1, r);
	}
}

int broken_cnt(int N, bool is_broken[])
{
	int cnt = 0;
	do
	{
		if (is_broken[N % 10])
		{
			cnt++;
		}
		N /= 10;
	} while (N);
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int now = 100;

	// �Է�
	int M;
	cin >> N >> M;
	bool is_broken[10] = { 0, };

	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		is_broken[tmp] = true;
	}

	// ��ǥ ä���� ���� ä���̰ų�, ��� ���ڹ�ư�� ���峵�� ��
	if (abs(N - now) == 0 || M == 10)
	{
		cout << abs(N - now);
		return 0;
	}
	// ������� ä�� ���ڿ� �ش��ϴ� ���峭 ��ư�� ������
	if (broken_cnt(N, is_broken) == 0)
	{
		cout << min((int)to_string(N).size(), abs(N - now));
		return 0;
	}

	// ���� ��ư ���ڿ� �����
	string numbers;
	for (int i = 0; i < 10; i++)
	{
		if (!is_broken[i])
		{
			numbers.push_back((char)i + '0');
		}
	}

	// �����ư���� ��ǥä�ΰ� ���� ����� ä�� �����
	cnt = abs(N - now);
	
	perm(numbers, "", 0, to_string(N).size() + 1);

	cout << cnt;

	return 0;
}