//https://www.acmicpc.net/problem/17406
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

template <typename T>
using d_vector = vector<vector<T>>;

// r, c : 회전하는 사각형의 가장 왼쪽 윗칸
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

	// 윗변을 오른쪽으로 한칸씩 이동
	for (int i = 0; i < len; ++i)
	{
		swap(A[info.r][++info.c], bf_val);
	}
	// 우변을 아래쪽으로 한칸씩 이동
	for (int i = 0; i < len; ++i)
	{
		swap(A[++info.r][info.c], bf_val);
	}
	// 밑변을 왼쪽으로 한칸씩 이동
	for (int i = 0; i < len; ++i)
	{
		swap(A[info.r][--info.c], bf_val);
	}
	// 좌변을 위쪽으로 한칸씩 이동
	for (int i = 0; i < len; ++i)
	{
		swap(A[--info.r][info.c], bf_val);
	}
}

void rotate(d_vector<int>& A, rtt_info info)
{
	// info.s > 0 일 동안 회전
	while (info.s)
	{
		// 네 변의 값들을 한칸씩 이동
		move_val(A, info);

		// (더 작은) 다음 회전사각형 준비
		++info.r;
		++info.c;
		--info.s;
	}
}

int get_min_sum_rotated_2d_vector(d_vector<int> A, vector<rtt_info> &infos, vector<int> &order)
{
	// 배열 A회전 : order순서에 따른 info값 대로
	for (int idx : order)
	{
		rotate(A, infos[idx]);
	}
	
	// 회전 후 배열 A의 최솟값 반환
	return get_min_sum_array(A);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
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

	// 순열을 위한 order배열 생성
	vector<int> order(K);
	for (int i = 0; i < K; ++i)
	{
		order[i] = i;
	}
	
	// infos 순열대로 배열A를 회전시키고 최솟값 구하기
	int min_val = numeric_limits<int>::max();
	do {
		
		int val = get_min_sum_rotated_2d_vector(A, infos, order);
		min_val = min(min_val, val);

	} while (next_permutation(order.begin(), order.end()));

	// 출력
	cout << min_val;

	return 0;
}