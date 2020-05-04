//https://www.acmicpc.net/problem/15649
#include <iostream>

using namespace std;

const int MAX = 8;
int visited[MAX + 1];
char output[MAX * 2 + 1];

void perm(int N, int M, int depth)
{
	// depth가 목표 길이에 도달하면 출력
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

	// 1~N까지의 숫자 중에서 M 자릿수 숫자 조합 만들기
	for (int i = 1; i <= N; i++)
	{
		// 이전에 선택하지 않은 숫자중에서 다음 숫자 선택
		if (!visited[i])
		{
			visited[i] = true;
			output[depth * 2] = i + '0';
			output[depth * 2 + 1] = ' ';
			perm(N, M, depth + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	perm(N, M, 0);

	return 0;
}