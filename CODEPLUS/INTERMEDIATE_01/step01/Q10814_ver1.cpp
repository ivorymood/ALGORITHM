//https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
	int order, age;
	string name;
};

// age��, �Էµ� ������� ����
bool compare(const member &A, const member &B)
{
	if (A.age != B.age)
	{
		return A.age < B.age;
	}
	return A.order < B.order;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<member> v(N);
	for (int i = 0; i < N; ++i)
	{
		v[i].order = i;
		cin >> v[i].age >> v[i].name;
	}

	// compare ���Ǵ�� ����
	sort(v.begin(), v.end(), compare);

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}