//https://www.acmicpc.net/problem/10815
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector<int>& cards, int left, int right, int target)
{
	// ã�� ���� ���� ���
	if (left > right)
	{
		return false;
	}

	int mid = (left + right) / 2;
	int mid_val = cards[mid];

	// ���� ã����
	if (mid_val == target)
	{
		return true;
	}
	// �߰� ���� target���� ������ : [mid + 1, right]�������� �� Ž��
	else if (mid_val < target)
	{
		return binary_search(cards, mid + 1, right, target);
	}
	// �߰� ���� target���� ũ�� : [left, mid - 1]�������� �� Ž��
	else 
	{
		return binary_search(cards, left, mid - 1, target);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M;
	cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cards[i];
	}

	// �̺�Ž���� ���� �������� ����
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int test;
		cin >> test;
		// �� �׽�Ʈ���̽����� ���� cards�� �ִ��� �̺�Ž������ Ȯ��
		cout << binary_search(cards, 0, N - 1, test) << ' ';
	}

	return 0;
}