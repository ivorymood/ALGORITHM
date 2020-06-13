//https://www.acmicpc.net/problem/9019
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MOD = 10000;
enum { D, S, L, R };
string dslr = "DSLR";
bool visit[MOD];
int bf[MOD];
char ops[MOD];

// D S L R 연산 결과 반환
int operation(int n, int op)
{
	int t_mod = MOD / 10;

	if (op == D)
	{
		return (n * 2) % MOD;
	}
	else if (op == S)
	{
		return (n + MOD - 1) % MOD;
	}
	else if (op == L)
	{
		return (n % t_mod) * 10 + n / t_mod;
	}
	else if (op == R)
	{
		return (n % 10) * t_mod + (n / 10);
	}
	return n;
}

// end숫자부터 start숫자까지 역추적해서 op출력
void print(int n)
{
	if (bf[n] == -1)
	{
		return;
	}

	print(bf[n]);

	cout << ops[n];
}

void bfs(int A, int B)
{
	// 큐에 start숫자 push
	queue<int> q;
	q.push(A);

	// 방문체크, 이전 인덱스 배열에 -1 저장.
	visit[A] = true;
	bf[A] = -1;

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		// end숫자에 도착하면 출력 후 종료
		if (n == B)
		{
			print(n);
			cout << '\n';
			return;
		}

		// DSLR 연산 4가지 진행
		for (int i = 0; i < 4; ++i)
		{
			// 다음 숫자를 아직 방문한적이 없다면
			int next = operation(n, i);
			if (!visit[next])
			{
				// 방문체크, 연산 char 저장, bf배열에 현재 숫자 저장.
				visit[next] = true;
				ops[next] = dslr[i];
				bf[next] = n;

				// 큐에 다음 숫자 push
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		// 입력
		int A, B;
		cin >> A >> B;

		// 배열 초기화
		memset(visit, 0, sizeof(visit));
		memset(ops, 0, sizeof(ops));
		memset(bf, 0, sizeof(bf));

		// A ~ B로 변환하기 위한 최소 명령어 출력
		bfs(A, B);
	}

	return 0;
}