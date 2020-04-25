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

	// �Է�
	string input;
	cin >> input;
	int len = input.size();

	/*
		���� ���ڿ��� �״�� �ְ�, 
		���ڿ��� ��½�ų �ε��� ���� �����ϴ� ���
	*/

	// ���Ϳ� �� 0 < idx < len  �ε��� �� ����ֱ�
	vector<int> str_idx(len);
	for (int i = 0; i < len; i++)
	{
		str_idx[i] = i;
	}

	/*
		�����Լ��� ���ο� ���ı��� ����

		���ڿ��� ����Ű�� �����͸� ����ؼ�
		u ��°���� ���۵Ǵ� ���ڿ���
		v ��°���� ���۵Ǵ� ���ڿ��� ��.
		�� ����� ������������ ���� ����
	*/
	sort(str_idx.begin(), str_idx.end()
		, [&input](int u, int v) 
		{
			return strcmp(input.c_str() + u, input.c_str() + v) < 0;
		}
	);
	
	/*
		���ĵ� ������ ��Ұ��� �ش��ϴ� �ε������� ���ڿ� ���.

		ex) ���Ͱ� 1 5 2 4 3 ���� ���ĵǾ��ٰ� �ϸ�,
		���ڿ��� 1��° ���ں���, 5��° ���ں���, 2��° ���ں����� ������ ��µȴ�.
	*/
	for (int &i : str_idx)
	{
		cout << input.substr(i) << '\n';
	}

	return 0;
}