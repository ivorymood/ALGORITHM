//https://www.acmicpc.net/problem/1406
#include <iostream>
#include <cstring>

using namespace std;

// main함수 스택사이즈 초과 에러(C6262)를 피하기 위해 전역변수로 선언
const int MAX = 600001;
char arr_left[MAX];
char arr_right[MAX];

int main()
{
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// left배열에 초기 문자열 입력
	cin >> arr_left;
	int idx_left = strlen(arr_left);
	int idx_right = 0;

	int n;
	cin >> n;
	while (n--)
	{
		// 각 배열의 idx를 기준으로 커서의 왼쪽/오른쪽 구분
		char cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (idx_left <= 0)
			{
				continue;
			}
			arr_right[idx_right++] = arr_left[--idx_left];
			break;

		case 'D':
			if (idx_right <= 0)
			{
				continue;
			}
			arr_left[idx_left++] = arr_right[--idx_right];
			break;

		case 'B':
			if (idx_left <= 0)
			{
				continue;
			}
			idx_left--;
			break;

		case 'P':
			cin >> arr_left[idx_left++];
			break;
		}
	}

	// right배열 -> left배열 옮기기
	while (idx_right >= 0)
	{
		arr_left[idx_left++] = arr_right[--idx_right];
	}

	// 출력
	cout << arr_left;

	return 0;
}