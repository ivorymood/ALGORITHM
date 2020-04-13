//https://www.acmicpc.net/problem/10818
#pragma warning(disable:4996)
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int max, min;
	scanf("%d", &max);
	min = max;

	for (int i = 1; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		max = (max < num) ? num : max;
		min = (min > num) ? num : min;
	}

	printf("%d %d", min, max);

	return 0;
}