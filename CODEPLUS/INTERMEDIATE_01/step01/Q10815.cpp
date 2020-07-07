//https://www.acmicpc.net/problem/10815
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector<int>& cards, int left, int right, int target)
{
	// 찾는 값이 없는 경우
	if (left > right)
	{
		return false;
	}

	int mid = (left + right) / 2;
	int mid_val = cards[mid];

	// 값을 찾으면
	if (mid_val == target)
	{
		return true;
	}
	// 중간 값이 target보다 작으면 : [mid + 1, right]범위에서 재 탐색
	else if (mid_val < target)
	{
		return binary_search(cards, mid + 1, right, target);
	}
	// 중간 값이 target보다 크면 : [left, mid - 1]범위에서 재 탐색
	else 
	{
		return binary_search(cards, left, mid - 1, target);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N, M;
	cin >> N;
	vector<int> cards(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cards[i];
	}

	// 이분탐색을 위한 오름차순 정렬
	sort(cards.begin(), cards.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int test;
		cin >> test;
		// 각 테스트케이스들의 값이 cards에 있는지 이분탐색으로 확인
		cout << binary_search(cards, 0, N - 1, test) << ' ';
	}

	return 0;
}