//https://www.acmicpc.net/problem/1874
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 테스트 횟수 입력받고 버퍼 비우기 
	int n;
	cin >> n;
	cin.ignore();

	stack<int> s;
	// 메모리&속도 향상을 위해 vector가 아닌 char 배열 선언
	char answer[400001];	
	int a_i = 0;

	for (int i = 0, k = 1; i < n; i++)
	{
		// 한번에 하나의 숫자 입력받고 버퍼 비우기
		int input;
		cin >> input;
		cin.ignore();

		// 스택이 비었거나, top이 input보다 작다면 --> top이 input과 같아질때까지 push
		if (s.empty() || s.top() < input)
		{
			while (k <= input)
			{
				s.push(k);
				k++;
				answer[a_i++] = '+';
				answer[a_i++] = '\n';
			}
		}
		// (스택이 비지 않고) top이 input보다 크다면 --> 불가능
		else if (s.top() > input)
		{
			break;
		}

		// 스택이 비지 않고, top이 input과 같다면 --> pop
		if (!s.empty() && s.top() == input)
		{
			s.pop();
			answer[a_i++] = '-';
			answer[a_i++] = '\n';
		}
	}

	// 문자열 끝 마무리
	answer[a_i] = '\0';

	// 스택이 비었다면 답안 출력, 아니라면 NO출력
	cout << ((s.empty()) ? answer : "NO");

	return 0;
}