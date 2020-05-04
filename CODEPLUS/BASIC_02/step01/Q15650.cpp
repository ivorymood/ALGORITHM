//https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
char output[MAX * 2 + 1];
bool visited[MAX + 1];

void perm(int N, int M, int start, int depth)
{
	// depth가 M에 도달하면 출력
	if (depth == M)
	{
		cout << output << '\n';
		return;
	}

	// 인수 start 값부터 N까지 수 중에서 M개의 숫자 조합
	for (int i = start; i <= N; i++)
	{
		// 이전에 선택하지 않은 숫자만 선택
		if (!visited[i])
		{
			visited[i] = true;
			output[depth * 2] = i + '0';
			output[depth * 2 + 1] = ' ';
			
			// 오름차순: 다음숫자는 현재 숫자보다 더 큰 숫자가 와야함.
			// start 파라미터 값으로 i + 1 넘기기
			perm(N, M, i + 1, depth + 1);
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

	perm(N, M, 1, 0);

	return 0;
}