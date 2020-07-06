//https://www.acmicpc.net/problem/10825
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

// kor��������, eng ��������, math ��������, name ������ ����
bool compare(const student &A, const student &B)
{
	if (A.kor != B.kor)
	{
		return A.kor > B.kor;
	}
	if (A.eng != B.eng)
	{
		return A.eng < B.eng;
	}
	if (A.math != B.math)
	{
		return A.math > B.math;
	}

	return A.name < B.name;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<student> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	// ����
	sort(v.begin(), v.end(), compare);

	// ���
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].name << '\n';
	}

	return 0;
}