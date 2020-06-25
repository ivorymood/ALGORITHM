//https://www.acmicpc.net/problem/10610
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	string num;
	cin >> num;
	
	// 내림차순 정렬
	sort(num.begin(), num.end(), [](char A, char B) {
		return A > B;
		});

	// 각 자리숫자의 합 구하기
	int sum = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		sum += num[i] - '0';
	}

	// 합이 3으로 나누어 떨어지지 않거나, 맨 뒷자리가 0이 아니면 실패
	if (sum % 3 != 0 || num.back() != '0')
	{
		cout << -1;
	}
	else
	{
		cout << num;
	}

	return 0;
}