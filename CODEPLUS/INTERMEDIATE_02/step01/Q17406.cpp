//https://www.acmicpc.net/problem/17406
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

template <typename T>
using d_vector = vector<vector<T>>;

// r, c : ȸ���ϴ� �簢���� ���� ���� ��ĭ
struct rtt_info 
{
	int r, c, s;
};

int get_min_sum_array(d_vector<int> &A)
{
	int min_sum = numeric_limits<int>::max();
	for (int i = 0; i < A.size(); ++i)
	{
		int sum = 0;
		for (int j = 0; j < A[i].size(); ++j)
		{
			sum += A[i][j];
		}
		min_sum = min(sum, min_sum);
	}
	return min_sum;
}

void inline swap(int &val1, int &val2)
{
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}

void move_val(d_vector<int>& A, rtt_info info)
{
	int len = info.s * 2;
	int bf_val = A[info.r][info.c];

	// ������ ���������� ��ĭ�� �̵�
	for (int i = 0; i < len; ++i)
	{
		swap(A[info.r][++info.c], bf_val);
	}
	// �캯�� �Ʒ������� ��ĭ�� �̵�
	for (int i = 0; i < len; ++i)
	{
		swap(A[++info.r][info.c], bf_val);
	}
	// �غ��� �������� ��ĭ�� �̵�
	for (int i = 0; i < len; ++i)
	{
		swap(A[info.r][--info.c], bf_val);
	}
	// �º��� �������� ��ĭ�� �̵�
	for (int i = 0; i < len; ++i)
	{
		swap(A[--info.r][info.c], bf_val);
	}
}

void rotate(d_vector<int>& A, rtt_info info)
{
	// info.s > 0 �� ���� ȸ��
	while (info.s)
	{
		// �� ���� ������ ��ĭ�� �̵�
		move_val(A, info);

		// (�� ����) ���� ȸ���簢�� �غ�
		++info.r;
		++info.c;
		--info.s;
	}
}

int get_min_sum_rotated_2d_vector(d_vector<int> A, vector<rtt_info> &infos, vector<int> &order)
{
	// �迭 Aȸ�� : order������ ���� info�� ���
	for (int idx : order)
	{
		rotate(A, infos[idx]);
	}
	
	// ȸ�� �� �迭 A�� �ּڰ� ��ȯ
	return get_min_sum_array(A);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N, M, K;
	cin >> N >> M >> K;
	d_vector<int> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> A[i][j];
		}
	}
	vector<rtt_info> infos(K);
	for (int i = 0; i < K; ++i)
	{
		int R, C, S;
		cin >> R >> C >> S;

		infos[i].r = R - S - 1;
		infos[i].c = C - S - 1;
		infos[i].s = S;
	}

	// ������ ���� order�迭 ����
	vector<int> order(K);
	for (int i = 0; i < K; ++i)
	{
		order[i] = i;
	}
	
	// infos ������� �迭A�� ȸ����Ű�� �ּڰ� ���ϱ�
	int min_val = numeric_limits<int>::max();
	do {
		
		int val = get_min_sum_rotated_2d_vector(A, infos, order);
		min_val = min(min_val, val);

	} while (next_permutation(order.begin(), order.end()));

	// ���
	cout << min_val;

	return 0;
}