//https://www.acmicpc.net/problem/1541
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	string line;
	cin >> line;

	// 문자열을 파싱하여 숫자는 nums벡터에
	// 연산자는 +이면 signs벡터에 +1을, -이면 -1을 signs벡터에 push한다
	vector<int> nums;
	vector<int> signs;
	signs.push_back(1);
	int num = 0;
	for (int i = 0; i < line.size(); ++i)
	{
		char c = line[i];
		if (c == '+' || c == '-')
		{
			nums.push_back(num);
			num = 0;

			signs.push_back((c == '+') ? 1 : -1);
		}
		else
		{
			num *= 10;
			num += line[i] - '0';
		}
	}
	nums.push_back(num);

	
	/*
		식의 결과를 최소로 만들기 위해서는
		- 연산자 이후를 모두 괄호로 묶어주어야 한다.
		즉 -연산자가 한번이라도 나온다면 그 뒤의 수는 모두 음수라고 판단할 수 있다.
	*/
	int res = 0;
	bool minus = false;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (signs[i] == -1)
		{
			minus = true;
		}

		if (minus)
		{
			res -= nums[i];
		}
		else
		{
			res += nums[i];
		}
	}

	cout << res;


	return 0;
}