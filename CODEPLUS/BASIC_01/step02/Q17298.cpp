//https://www.acmicpc.net/problem/17298
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	// ����: ��ū���� ���� ã�� ���� ��
	stack<int> yet;
	yet.push(0);

	// ��ū�� ã��
	vector<int> nge(n);
	for (int i = 1; i < n; i++)
	{
		// input[i]�� top�� ��ū���̸�
		while (!yet.empty() && input[yet.top()] < input[i])
		{
			nge[yet.top()] = input[i];
			yet.pop();
		}
		yet.push(i);
	}

	// ��ū���� ã�� ���� �� ó��
	while (!yet.empty())
	{
		nge[yet.top()] = -1;
		yet.pop();
	}

	// ���
	for (int i = 0; i < n; i++)
	{
		cout << nge[i] << ' ';
	}

	return 0;
}