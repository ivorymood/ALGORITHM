//https://www.acmicpc.net/problem/10818
#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> input;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		input.push_back(num);
	}

	int max = input[0];
	int min = input[0];

	for (int i = 0; i < n; i++)
	{
		max = (max < input[i]) ? input[i] : max;
		min = (min > input[i]) ? input[i] : min;
	}

	printf("%d %d", min, max);

	return 0;
}