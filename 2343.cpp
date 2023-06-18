#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	int st = 0, ed = 0;

	cin >> N >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		if (v[i] > st)
			st = v[i];
		ed += v[i];
	}

	while (st <= ed)
	{
		int pv = (st + ed) / 2;
		int sum = 0, cnt = 0;

		for (int i = 0; i < N; i++)
		{
			if (sum + v[i] > pv)
			{
				sum = 0;
				++cnt;
			}
			sum += v[i];
		}
		if (sum != 0)
			++cnt;

		if (cnt > M)
		{
			st = pv + 1;
		}
		else
		{
			ed = pv - 1;
		}

	}

	cout << st << "\n";

	return 0;
}