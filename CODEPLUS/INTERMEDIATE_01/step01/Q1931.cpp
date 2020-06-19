//https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct conf {
	int start, end;
};

bool compare(conf a, conf b) {
	if (a.end != b.end)
	{
		return a.end < b.end;
	}
	return a.start < b.start;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	int N;
	cin >> N;
	vector<conf> confs(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> confs[i].start >> confs[i].end;
	}

	// end�� ���� ��, start�� ���� ������ confs���� ����
	sort(confs.begin(), confs.end(), compare);

	int now = 0, cnt = 0;
	for (int i = 0; i < confs.size(); ++i)
	{
		// ���� <= ȸ�� start �ð��� �� 
		// : ����ð��� ȸ�� ���ð����� �ٲٰ� ī����
		if (now <= confs[i].start)
		{
			now = confs[i].end;
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}