//https://www.acmicpc.net/problem/1541
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	string line;
	cin >> line;

	// ���ڿ��� �Ľ��Ͽ� ���ڴ� nums���Ϳ�
	// �����ڴ� +�̸� signs���Ϳ� +1��, -�̸� -1�� signs���Ϳ� push�Ѵ�
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
		���� ����� �ּҷ� ����� ���ؼ���
		- ������ ���ĸ� ��� ��ȣ�� �����־�� �Ѵ�.
		�� -�����ڰ� �ѹ��̶� ���´ٸ� �� ���� ���� ��� ������� �Ǵ��� �� �ִ�.
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