//https://www.acmicpc.net/problem/15649
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	
	string nCm;
	
	for (int i = 1; i <= N; i++)
	{
		nCm.push_back((char)i + '0');
	}

	int tmp = 0;
	do 
	{
		int res = stoi(nCm.substr(0, M));

		if (res > tmp)
		{
			for (int i = 0; i < M; i++)
			{
				cout << nCm[i] << " ";
			}
			cout << '\n';
			tmp = res;
		}
	} while (next_permutation(nCm.begin(), nCm.end()));

	return 0;
}