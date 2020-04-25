//https://www.acmicpc.net/problem/11656
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	string input;
	cin >> input;
	int len = input.size();

	/*
		들어온 문자열은 그대로 있고, 
		문자열을 출력시킬 인덱스 값만 정렬하는 방법
	*/

	// 벡터에 각 0 < idx < len  인덱스 값 집어넣기
	vector<int> str_idx(len);
	for (int i = 0; i < len; i++)
	{
		str_idx[i] = i;
	}

	/*
		람다함수로 새로운 정렬기준 설정

		문자열을 가리키는 포인터를 사용해서
		u 번째부터 시작되는 문자열과
		v 번째부터 시작되는 문자열을 비교.
		비교 결과를 오름차순으로 벡터 정렬
	*/
	sort(str_idx.begin(), str_idx.end()
		, [&input](int u, int v) 
		{
			return strcmp(input.c_str() + u, input.c_str() + v) < 0;
		}
	);
	
	/*
		정렬된 벡터의 요소값에 해당하는 인덱스부터 문자열 출력.

		ex) 벡터가 1 5 2 4 3 으로 정렬되었다고 하면,
		문자열은 1번째 문자부터, 5번째 문자부터, 2번째 문자부터의 순으로 출력된다.
	*/
	for (int &i : str_idx)
	{
		cout << input.substr(i) << '\n';
	}

	return 0;
}