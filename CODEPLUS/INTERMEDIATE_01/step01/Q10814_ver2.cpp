//https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
	int age;
	string name;
};

// age순 정렬
bool compare(const member& A, const member& B)
{
	return A.age < B.age;
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
		cin >> v[i].age >> v[i].name;
	}

	// compare 조건대로 정렬 (조건이 같으면 입력된 순서 유지)
	stable_sort(v.begin(), v.end(), compare);

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}