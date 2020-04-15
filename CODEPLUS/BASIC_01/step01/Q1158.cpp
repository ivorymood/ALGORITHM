//https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// 입출력 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력값 받기, queue에 [1, N]숫자 push
	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	// N - 1회까지만 출력하기
	cout << '<';
	for (int i = 0; i < N - 1; i++)
	{
		// K보다 작은 번째 숫자는 출력X, 다시 push
		for (int j = 1; j < K; j++)
		{
			q.push(q.front());
			q.pop();
		}

		// K번째 숫자만 출력O
		cout << q.front() << ", ";
		q.pop();
	}

	// 마지막 N번째 숫자 출력
	cout << q.front() << '>';

	return 0;
}