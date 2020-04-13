//https://www.acmicpc.net/problem/10953
#pragma warning(disable: 4996)
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	while (N-- > 0)
	{
		int A, B;
		scanf("%d,%d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}