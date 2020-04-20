//https://www.acmicpc.net/problem/14002
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_answer(vector<int> &A, vector<int> &bf_idx, int idx)
{
	if (idx == -1)
	{
		return;
	}
	print_answer(A, bf_idx, bf_idx[idx]);
	cout << A[idx] << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	// size 벡터와 Lis수열을 위한 인덱스 벡터 구하기
	vector<int> size(n, 1);
	vector<int> bf_idx(n, -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && size[j] + 1 > size[i])
			{
				size[i] = size[j] + 1;
				bf_idx[i] = j;
			}
		}
	}

	// 최대길이 구하기
	vector<int>::iterator max_iter = max_element(size.begin(), size.end());
	int max_idx = max_iter - size.begin();
	
	// 출력
	cout << *max_iter << '\n';
	print_answer(A, bf_idx, max_idx);

	return 0;
}