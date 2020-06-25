//https://www.acmicpc.net/problem/1202
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct jewel {
	int weight, value;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, K;
	cin >> N >> K;
	vector<jewel> jewels(N);
	multiset<int> bags;
	for (int i = 0; i < N; ++i)
	{
		cin >> jewels[i].weight >> jewels[i].value;
	}
	for (int i = 0; i < K; ++i)
	{
		int bag;
		cin >> bag;
		bags.insert(bag);
	}

	// ���� ��ġ�� �������� �������� ����
	sort(jewels.begin(), jewels.end(), [](jewel& A, jewel& B) {

		return A.value > B.value;
		});

	/*
		1. ���� ��� �������� Ž��
		2. ������ ���Ժ��� ���ų� ū �ּ��� ���湫�� ã�� -> sum ���ϱ�
		3. �ش� ���� �����
	*/
	long long sum = 0;
	for (auto iter = jewels.begin(); iter != jewels.end(); ++iter)
	{
		auto it_bag = bags.lower_bound(iter->weight);

		if (it_bag != bags.end())
		{
			sum += iter->value;
			bags.erase(it_bag);
		}
	}

	cout << sum;

	return 0;
}