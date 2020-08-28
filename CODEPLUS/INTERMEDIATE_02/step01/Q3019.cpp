//https://www.acmicpc.net/problem/3019
#include <iostream>
#include <vector>

using namespace std;

// 주어진 타입으로 모양별 블록 생성
vector<vector<int>> getBlocks(int block_type)
{
	vector<vector<int>> block;
	switch (block_type)
	{
	case 1:
		block.push_back({ 0 });
		block.push_back({ 0, 0, 0, 0 });
		break;
	case 2:
		block.push_back({0, 0});
		break;
	case 3:
		block.push_back({ 0, 0, 1 });
		block.push_back({ 1, 0 });
		break;
	case 4:
		block.push_back({ 1, 0, 0 });
		block.push_back({ 0, 1 });
		break;
	case 5:
		block.push_back({ 0, 0, 0 });
		block.push_back({ 1, 0 });
		block.push_back({ 0, 1 });
		block.push_back({ 1, 0, 1 });
		break;
	case 6:
		block.push_back({ 0, 0, 0 });
		block.push_back({ 0, 0 });
		block.push_back({ 0, 1, 1 });
		block.push_back({ 2, 0 });
		break;
	case 7:
		block.push_back({ 0, 0, 0 });
		block.push_back({ 0, 0 });
		block.push_back({ 1, 1, 0 });
		block.push_back({ 0, 2 });
		break;
	}
	return block;
}

bool checkBlock(vector<int> &board, vector<int> &block, int idx)
{
	// 보드 범위 체크
	if (idx + block.size() > board.size())
	{
		return false;
	}

	// 블록의 2번째 칸부터 비교
	for (int i = 1; i < block.size(); ++i)
	{
		int brd_idx = idx + i;

		// (블록의 현재 위치값 - 이전 인덱스 위치값) != (보드의 현재 위치값 - 이전 인덱스 위치값) 이면 false 반환
		if (block[i] - block[i - 1] != board[brd_idx] - board[brd_idx - 1])
		{
			return false;
		}
	}

	return true;
}

// 블록을 놓을 수 있는 방법 수 계산하기
int countLocations(vector<int> &board, vector<vector<int>> &blocks)
{
	int cnt = 0;
	for (int idx = 0; idx < board.size(); ++idx) 
	{
		for (vector<int> &block : blocks)
		{
			// 보드의 idx위치부터 현재 블록 모양을 놓을 수 있으면 ++cnt
			if (checkBlock(board, block, idx))
			{
				++cnt;
			}
		}
	}
	return cnt;
}

int main() 
{
	// 입력
	int C, P;
	cin >> C >> P;
	vector<int> board(C);
	for (int i = 0; i < C; ++i) 
	{
		int num;
		cin >> num;
		board[i] = num;
	}

	// 주어진 타입의 블록으로, 보드에 블록을 놓을 수 있는 방법 구하기
	vector<vector<int>> blocks = getBlocks(P);
	cout << countLocations(board, blocks);

	return 0;
}