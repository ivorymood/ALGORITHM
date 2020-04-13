//https://www.acmicpc.net/problem/11719
#include <stdio.h>

int main()
{
	char my_string[101];

	while (fgets(my_string, sizeof(my_string), stdin))
	{
		printf("%s", my_string);
	}

	return 0;
}