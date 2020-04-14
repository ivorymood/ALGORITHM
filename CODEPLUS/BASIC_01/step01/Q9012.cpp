//https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 횟수 입력받고 버퍼 비우기
	int n;
	cin >> n;
	cin.ignore();

	while (n--)
	{
		string line;
		getline(cin, line);
		
		// '(' 와 ')' 갯수차이를 구하기 
		// '(' : +1
		// ')' : -1
		int sum = 0;
		for (char c : line)
		{
			
			if (c == '(')
			{
				sum++;
			}
			else if (c == ')')
			{
				sum--;
			}

			// 입력받은 '('보다 ')'가 많을 때
			if (sum < 0)
			{
				break;
			}
		}

		// '(' 와 ')' 갯수가 동일하면 YES, 아니면 NO 출력
		cout << ((sum == 0) ? "YES" : "NO") << '\n';
	}
	return 0;
}