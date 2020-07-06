//https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
	int order, age;
	string name;
};

// age순, 입력된 순서대로 정렬
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

	// 입력
	int N;
	cin >> N;
	vector<member> v(N);
	for (int i = 0; i < N; ++i)
	{
		v[i].order = i;
		cin >> v[i].age >> v[i].name;
	}

	// compare 조건대로 정렬
	sort(v.begin(), v.end(), compare);

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}