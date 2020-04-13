//https://www.acmicpc.net/problem/1924
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int monthly_dates[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int month, day, day_sum = 0;

	cin >> month >> day;

	for (int i = 0; i < month - 1; i++)
	{
		day_sum += monthly_dates[i];
	}

	day_sum += day;

	cout << days[day_sum % 7];

	return 0;
}