//https://www.acmicpc.net/problem/2580
#include <iostream>

using namespace std;

const int N = 9;
bool vert[N][N + 1];
bool hori[N][N + 1];
bool box[N][N + 1];
int sdoku[N][N];

// 스도쿠 프린트
void print_sdoku()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << sdoku[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool go(int num)
{
	// 마지막 칸까지 모두 채우면 프린트 후 종료
	if (num == N * N)
	{
		print_sdoku();
		return true;
	}

	// 행/열/박스 n번째인지 구하기
	int x = num / N;
	int y = num % N;
	int idx = (x / 3) * 3 + (y / 3);

	// 빈칸이 아니면 바로 다음칸으로 go재귀함수 호출
	if (sdoku[x][y] != 0)
	{
		return go(num + 1);
	}
	// 빈칸이면
	else
	{
		/*
			1 ~ 9까지의 숫자 중에서
			행/열/박스 bool배열에서 공통적으로 false인 숫자를 빈칸에 저장하고
			각 배열의 해당 숫자에 true 체크한 후 go 재귀함수 호출
		*/
		for (int k = 1; k <= N; ++k)
		{
			if (!(vert[x][k] || hori[y][k] || box[idx][k]))
			{
				sdoku[x][y] = k;
				vert[x][k] = hori[y][k] = box[idx][k] = true;
				
				// 한번이라도 마지막칸에 도달했다면 종료
				if (go(num + 1))
				{
					return true;
				}
				sdoku[x][y] = 0;
				vert[x][k] = hori[y][k] = box[idx][k] = false;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> sdoku[i][j];

			/*
				빈칸이 아니라면
				행/열/박스 bool배열에 true 체크하기
			*/
			if (sdoku[i][j] != 0)
			{
				int idx = (i / 3) * 3 + (j / 3);
				box[idx][sdoku[i][j]] = true;
				vert[i][sdoku[i][j]] = true;
				hori[j][sdoku[i][j]] = true;
			}
		}
	}

	// 완성 스도쿠를 구한 후 출력하기
	go(0);

	return 0;
}