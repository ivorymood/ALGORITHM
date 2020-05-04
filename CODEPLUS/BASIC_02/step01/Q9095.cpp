//https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int MAX = 10;
	int cnt[MAX + 1] = { 0, };
	
	for (int n = 1; n <= MAX; n++)
	{
		for (int l1 = 1; l1 <= 3; l1++)
		{
			if (l1 == n)
			{
				cnt[n]++;
			}
			for (int l2 = 1; l2 <= 3; l2++)
			{
				if (l1 + l2 == n)
				{
					cnt[n]++;
				}
				for (int l3 = 1; l3 <= 3; l3++)
				{
					if (l1 + l2 + l3 == n)
					{
						cnt[n]++;
					}
					for (int l4 = 1; l4 <= 3; l4++)
					{
						if (l1 + l2 + l3 + l4 == n)
						{
							cnt[n]++;
						}
						for (int l5 = 1; l5 <= 3; l5++)
						{
							if (l1 + l2 + l3 + l4 + l5 == n)
							{
								cnt[n]++;
							}
							for (int l6 = 1; l6 <= 3; l6++)
							{
								if (l1 + l2 + l3 + l4 + l5 + l6 == n)
								{
									cnt[n]++;
								}
								for (int l7 = 1; l7 <= 3; l7++)
								{
									if (l1 + l2 + l3 + l4 + l5 + l6 + l7 == n)
									{
										cnt[n]++;
									}
									for (int l8 = 1; l8 <= 3; l8++)
									{
										if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 == n)
										{
											cnt[n]++;
										}
										for (int l9 = 1; l9 <= 3; l9++)
										{
											if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 == n)
											{
												cnt[n]++;
											}
											for (int l0 = 1; l0 <= 3; l0++)
											{
												if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l0 == n)
												{
													cnt[n]++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << cnt[n] << '\n';
	}

	return 0;
}