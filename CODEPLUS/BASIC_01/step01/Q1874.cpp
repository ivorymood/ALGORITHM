//https://www.acmicpc.net/problem/1874
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	// ����� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �׽�Ʈ Ƚ�� �Է¹ް� ���� ���� 
	int n;
	cin >> n;
	cin.ignore();

	stack<int> s;
	// �޸�&�ӵ� ����� ���� vector�� �ƴ� char �迭 ����
	char answer[400001];	
	int a_i = 0;

	for (int i = 0, k = 1; i < n; i++)
	{
		// �ѹ��� �ϳ��� ���� �Է¹ް� ���� ����
		int input;
		cin >> input;
		cin.ignore();

		// ������ ����ų�, top�� input���� �۴ٸ� --> top�� input�� ������������ push
		if (s.empty() || s.top() < input)
		{
			while (k <= input)
			{
				s.push(k);
				k++;
				answer[a_i++] = '+';
				answer[a_i++] = '\n';
			}
		}
		// (������ ���� �ʰ�) top�� input���� ũ�ٸ� --> �Ұ���
		else if (s.top() > input)
		{
			break;
		}

		// ������ ���� �ʰ�, top�� input�� ���ٸ� --> pop
		if (!s.empty() && s.top() == input)
		{
			s.pop();
			answer[a_i++] = '-';
			answer[a_i++] = '\n';
		}
	}

	// ���ڿ� �� ������
	answer[a_i] = '\0';

	// ������ ����ٸ� ��� ���, �ƴ϶�� NO���
	cout << ((s.empty()) ? answer : "NO");

	return 0;
}