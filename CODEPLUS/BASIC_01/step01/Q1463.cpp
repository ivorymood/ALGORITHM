//https://www.acmicpc.net/problem/1463
#include <iostream>

using namespace std;

const int MAX = 1000000;
int M[MAX + 1];

// 점화식 : D[n] = min(D[n - 1] + 1, D[n / 2] + 1, D[n / 3] + 1)
int make_one(int n)
{
	// 종료조건
	if (n == 1)
	{
		return 0;
	}

	if (M[n] > 0)
	{
		return M[n];
	}

	// 10->9->3->1 과 같은 반례가 있을 수 있으므로,
	// 1 ~ N 까지의 모든 경우의 수를 미리 저장
	M[n] = make_one(n - 1) + 1;
	
	// 현재 저장된 값 > 새로 구한 값일 때, 갈음하기
	if (n % 2 == 0)
	{
		int temp = make_one(n / 2) + 1;
		if (M[n] > temp) M[n] = temp;
	}

	if (n % 3 == 0)
	{
		int temp = make_one(n / 3) + 1;
		if (M[n] > temp) M[n] = temp;
	}

	return M[n];
}

int main()
{
	int n;
	cin >> n;

	make_one(n);

	cout << M[n];

	return 0;
}