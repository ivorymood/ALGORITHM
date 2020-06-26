//https://www.acmicpc.net/problem/1783
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력 : 행 / 열
	int height, width;
	cin >> height >> width;
	
	if (height == 1)
	{
		cout << 1;
	}
	else if (height == 2)
	{
		// 이동 방법 제약 조건 : 방문지점이 5 이상이려면 모든 이동 방법을 사용한 상태여야 함
		cout << min(4, (width + 1) / 2);
	}
	else 
	{
		if (width < 7)
		{
			// 이동 방법 제약 조건 : 방문지점이 5 이상이려면 모든 이동 방법을 사용한 상태여야 함
			cout << min(4, width);
		}
		else 
		{
			// 이동 방법 제약 조건 
			// : 최소 1번씩은 오른쪽으로 2칸 이동하는 방법을 써야함
			cout << width - 2;
		}
	}

	return 0;
}