//https://www.acmicpc.net/problem/1780
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

struct pos {
	int x, y;
};

// strt���� ���μ��� len�� ������ ���ڰ� ��� ������ Ȯ��
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
		strt���� ���μ��� len�� ������ ���ڰ� ��� ������
		: �ش� ���ڰ��� + 1
	*/
	if (same_num_area(paper, strt, len))
	{
		++nums[paper[strt.x][strt.y] + 1];
		return;
	}

	/*
		���� ���θ� 9�������� ������ 
		�� ������ ù��° ��ġ���� ���� ���̰����� ���ȣ��
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

	// �Է�
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

	// ���� ���ڷθ� ä���� (���ں�)���̰��� ���ϱ�
	nums = vector<int>(3);
	cut_paper(paper, {0, 0}, N);

	// ���
	for (int n : nums)
	{
		cout << n << '\n';
	}

	return 0;
}