//https://www.acmicpc.net/problem/1780
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

struct pos {
	int x, y;
};

// strt부터 가로세로 len의 영역의 숫자가 모두 같은지 확인
bool same_num_area(vector<vector<int>> &paper, pos &strt, int len)
{
	int num = paper[strt.x][strt.y];
	for (int i = strt.x; i < strt.x + len; ++i)
	{
		for (int j =  strt.y; j < strt.y + len; ++j)
		{
			if (paper[i][j] != num)
			{
				return false;
			}
		}
	}
	return true;
}

void cut_paper(vector<vector<int>> &paper, pos strt, int len)
{
	/*
		strt부터 가로세로 len의 영역의 숫자가 모두 같으면
		: 해당 숫자개수 + 1
	*/
	if (same_num_area(paper, strt, len))
	{
		++nums[paper[strt.x][strt.y] + 1];
		return;
	}

	/*
		가로 세로를 9구간으로 나누어 
		각 구간의 첫번째 위치값과 구간 길이값으로 재귀호출
	*/
	for (int i = strt.x; i < strt.x + len; i += len / 3)
	{
		for (int j = strt.y; j < strt.y + len; j += len / 3)
		{
			cut_paper(paper, {i, j}, len / 3);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<vector<int>> paper(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> paper[i][j];
		}
	}

	// 같은 숫자로만 채워진 (숫자별)종이개수 구하기
	nums = vector<int>(3);
	cut_paper(paper, {0, 0}, N);

	// 출력
	for (int n : nums)
	{
		cout << n << '\n';
	}

	return 0;
}