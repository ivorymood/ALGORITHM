//https://www.acmicpc.net/problem/2751
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &v, int left, int right)
{
	int pl = left;
	int pr = right;
	int x = v[(pl + pr) / 2];	// 피벗값 : L인덱스와 R인덱스의 중앙에 있는 값

	/*
		피벗값을 중심으로 L인덱스의 값과 R인덱스의 값을 교환
		L인덱스가 R인덱스보다 커지면 반복문 종료
	*/
	do {
		while (v[pl] < x) ++pl;
		while (v[pr] > x) --pr;
	
		if (pl <= pr)
		{
			swap(v[pl], v[pr]);
			++pl;
			--pr;
		}
	} while (pl <= pr);

	// 재귀함수 호출로 더 작은 부분에 대하여 똑같은 정렬과정 실행
	if (left < pr)
	{
		quick_sort(v, left, pr);
	}
	if (pl < right)
	{
		quick_sort(v, pl, right);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	// 퀵 정렬
	quick_sort(v, 0, N - 1);

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << v[i] << '\n';
	}

	return 0;
}