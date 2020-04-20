//https://www.acmicpc.net/problem/11053
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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
	
	// LIS 수열의 사이즈 구하기
	// 점화식 : D[i] = max(D[j]) + 1 (j < i && A[j] < A[i] 일 때)
	vector<int> size(n);
	for (int i = 0; i < n; i++)
	{
		size[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && size[j] + 1 > size[i])
			{
				size[i] = size[j] + 1;
			}
		}
	}

	// 가장 긴 길이 출력
	cout << *max_element(size.begin(), size.end()) << '\n'; 

	return 0;
}