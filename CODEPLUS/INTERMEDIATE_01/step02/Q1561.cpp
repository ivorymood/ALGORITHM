//https://www.acmicpc.net/problem/1561
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll N_MAX = 2000000000LL;
const ll T_MAX = 30;
ll N, M;

// �־��� time�ð����� ���̱ⱸ�� ź ���̵� �� ���ϱ�
ll cnt_passed(vector<ll> &rides, ll time)
{
	// 0�п��� ��� ���̱ⱸ�� ��������Ƿ�, sum�� M���� ����
	ll sum = M;
	for (int i = 0; i < M; ++i)
	{
		// �ش� �ð����� ���̱ⱸ�� ź ���̵� �� ī����
		sum += time / rides[i];
	}
	return sum;
}

void binary_search(vector<ll>& rides, ll &now, ll& passed)
{
	ll left = 0;
	ll right = N_MAX * T_MAX; // �ִ� ���̵� �� * �ִ� ���̱ⱸ �ð�

	while (left <= right)
	{
		// passed : mid�ð����� ���̱ⱸ�� ź ���̵� ��
		ll mid = (left + right) / 2;
		ll cnt = cnt_passed(rides, mid);

		if (cnt >= N)
		{
			// now : ������ ���̰� ���̱ⱸ�� Ÿ�� �ð���
			now = mid;
			right = mid - 1;
		}
		else
		{
			// passed_bf : mid�ð� ������ ���̱ⱸ�� ź ���̵� ��
			passed = cnt;
			left = mid + 1;
		}
	}
}

int get_ride_num(vector<ll> &rides, ll now, ll passed)
{
	for (int i = 0; i < M; ++i)
	{
		// now�� ����ִ� ���̱ⱸ�� �ִٸ�
		if (now % rides[i] == 0)
		{
			++passed;

			// ���̱ⱸ�� ź ���̵� ���� N�̸�, �ش� ���̱ⱸ ��ȣ ��ȯ
			if (passed == N)
			{
				return i + 1;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
	cin >> N >> M;
	vector<ll> rides(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> rides[i];
	}

	/*
		���̵� ���� ���̱ⱸ ������ ���� �� 
		: ������ ���̴� N��° ���̱ⱸ�� ź��
	*/
	if (N <= M)
	{
		cout << N;
	}
	else
	{
		/*
			now : ������ ���̰� ���̱ⱸ�� Ÿ�� �ð�
			passed : now �ð� ������ ���̱ⱸ�� ź ���̵� ��
			
			�̺�Ž������ now�� passed�� ���Ѵ�
		*/
		ll now = 0, passed = 0;
		binary_search(rides, now, passed);

		cout << get_ride_num(rides, now, passed);
	}
	 
	return 0;
}