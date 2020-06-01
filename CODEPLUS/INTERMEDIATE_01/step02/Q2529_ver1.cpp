//https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string numbers = "9876543210";

// �� ������ ũ�⸦ c�� �������� �Ǵ��Ͽ� bool ��ȯ
bool inline check(char ineuql, char A, char B)
{
	return (ineuql == '<') ? (A < B) : (A > B);
}

bool perm(vector<char> &inequal, vector<bool> &visit, string answer, int N, int cnt)
{
	// N���� �ڸ��� ��� �ϼ��ϸ� ��� �� ����
	if (cnt == N)
	{
		cout << answer << '\n';
		return true;
	}

	// numbers ���ڿ��� N��° �ڸ����� Ž��
	for (int i = 0; i < N; ++i)
	{
		if (!visit[i])
		{
			// ù��° �ڸ��̰ų�, ���ǿ� �����ϸ�
			if (cnt == 0 || check(inequal[cnt - 1], answer[cnt - 1], numbers[i]))
			{
				visit[i] = true;
				/*
					�ѹ��̶� �����ϸ� ����
					��������/�������� ���ڿ��� dfsŽ���ϱ� ������, 
					���� ó���� ���� ����� ���� ����/ū ����.
				*/
				if (perm(inequal, visit, answer + numbers[i], N, cnt + 1))
				{
					return true;
				}
				visit[i] = false;
			}
		}
	}
	return false;
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

	vector<bool> visit(K + 1);
	
	// �������� ���ĵ� numbers ���ڿ��� �������Ǵ�� K + 1����ŭ �����ϱ�.
	perm(inequal, visit, "", K + 1, 0);
	

	// visit���͸� false�� ä���
	fill(visit.begin(), visit.end(), 0);
	// �������� ����
	sort(numbers.begin(), numbers.end());
	

	// �������� ���ĵ� numbers ���ڿ��� �������Ǵ�� K + 1����ŭ �����ϱ�. 
	perm(inequal, visit, "", K + 1, 0);
	
	return 0;
}