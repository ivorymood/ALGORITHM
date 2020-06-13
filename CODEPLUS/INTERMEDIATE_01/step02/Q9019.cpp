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

// D S L R ���� ��� ��ȯ
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

// end���ں��� start���ڱ��� �������ؼ� op���
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
	// ť�� start���� push
	queue<int> q;
	q.push(A);

	// �湮üũ, ���� �ε��� �迭�� -1 ����.
	visit[A] = true;
	bf[A] = -1;

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		// end���ڿ� �����ϸ� ��� �� ����
		if (n == B)
		{
			print(n);
			cout << '\n';
			return;
		}

		// DSLR ���� 4���� ����
		for (int i = 0; i < 4; ++i)
		{
			// ���� ���ڸ� ���� �湮������ ���ٸ�
			int next = operation(n, i);
			if (!visit[next])
			{
				// �湮üũ, ���� char ����, bf�迭�� ���� ���� ����.
				visit[next] = true;
				ops[next] = dslr[i];
				bf[next] = n;

				// ť�� ���� ���� push
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
		// �Է�
		int A, B;
		cin >> A >> B;

		// �迭 �ʱ�ȭ
		memset(visit, 0, sizeof(visit));
		memset(ops, 0, sizeof(ops));
		memset(bf, 0, sizeof(bf));

		// A ~ B�� ��ȯ�ϱ� ���� �ּ� ��ɾ� ���
		bfs(A, B);
	}

	return 0;
}