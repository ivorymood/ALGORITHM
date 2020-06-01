//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� ������ ũ�⸦ c�� �������� �Ǵ��Ͽ� bool ��ȯ
bool inline condition(char ineuql, int A, int B)
{
	return (ineuql == '<') ? (A < B) : (A > B);
}

bool check_condition(vector<char> &inequal, vector<int> &numbers, int K)
{
	bool possible = true;
	for (int i = 0; i < K; ++i)
	{
		if (!condition(inequal[i], numbers[i], numbers[i + 1]))
		{
			possible = false;
			break;
		}
	}

	return possible;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int K;
	cin >> K;
	vector<char> inequal(K);
	for (int i = 0; i < K; ++i)
	{
		cin >> inequal[i];
	}

	vector<int> asc_numbers(K + 1);
	vector<int> desc_numbers(K + 1);

	for (int i = 0; i <= K; ++i)
	{
		asc_numbers[i] = i;
		desc_numbers[i] = 9 - i;
	}

	// �������� ���ĵ� numbers ���ڿ��� �������Ǵ�� K + 1����ŭ �����ϱ�.
	do
	{
		if (check_condition(inequal, desc_numbers, K))
		{
			for (int i = 0; i < K + 1; ++i)
			{
				cout << desc_numbers[i];
			}
			cout << '\n';
			break;
		}
	} while (prev_permutation(desc_numbers.begin(), desc_numbers.end()));
	

	// �������� ���ĵ� numbers ���ڿ��� �������Ǵ�� K + 1����ŭ �����ϱ�. 
	do 
	{
		if (check_condition(inequal, asc_numbers, K))
		{
			for (int i = 0; i < K + 1; ++i)
			{
				cout << asc_numbers[i];
			}
			cout << '\n';
			break;
		}
	} while (next_permutation(asc_numbers.begin(), asc_numbers.end()));

	return 0;
}