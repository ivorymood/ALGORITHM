//https://www.acmicpc.net/problem/3019
#include <iostream>
#include <vector>

using namespace std;

// �־��� Ÿ������ ��纰 ��� ����
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
	// ���� ���� üũ
	if (idx + block.size() > board.size())
	{
		return false;
	}

	// ����� 2��° ĭ���� ��
	for (int i = 1; i < block.size(); ++i)
	{
		int brd_idx = idx + i;

		// (����� ���� ��ġ�� - ���� �ε��� ��ġ��) != (������ ���� ��ġ�� - ���� �ε��� ��ġ��) �̸� false ��ȯ
		if (block[i] - block[i - 1] != board[brd_idx] - board[brd_idx - 1])
		{
			return false;
		}
	}

	return true;
}

// ����� ���� �� �ִ� ��� �� ����ϱ�
int countLocations(vector<int> &board, vector<vector<int>> &blocks)
{
	int cnt = 0;
	for (int idx = 0; idx < board.size(); ++idx) 
	{
		for (vector<int> &block : blocks)
		{
			// ������ idx��ġ���� ���� ��� ����� ���� �� ������ ++cnt
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
	// �Է�
	int C, P;
	cin >> C >> P;
	vector<int> board(C);
	for (int i = 0; i < C; ++i) 
	{
		int num;
		cin >> num;
		board[i] = num;
	}

	// �־��� Ÿ���� �������, ���忡 ����� ���� �� �ִ� ��� ���ϱ�
	vector<vector<int>> blocks = getBlocks(P);
	cout << countLocations(board, blocks);

	return 0;
}