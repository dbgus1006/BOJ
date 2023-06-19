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

	long N = 0, k = 0;
	long result = 0;

	cin >> N >> k;

	long st = 1, ed = k;

	while (st <= ed)
	{
		long mid = (st + ed) / 2;
		long cnt = 0;

		for (int i = 1; i < N + 1; i++)
		{
			cnt += min(mid / i, N);
		}

		if (cnt < k)
		{
			st = mid + 1;
		}
		if (cnt >= k)
		{
			result = mid;
			ed = mid - 1;
		}
	}

	cout << result << "\n";

	return 0;
}