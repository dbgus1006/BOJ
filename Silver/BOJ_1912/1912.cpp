#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<int> v;
static vector<int> dp;
static int N, res = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N);
	dp.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	dp[0] = v[0];
	res = dp[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = dp[i - 1] + v[i];

		if (dp[i] < v[i])
		{
			dp[i] = v[i];
		}

		if (dp[i] > res)
		{
			res = dp[i];
		}
	}

	cout << res << "\n";

	return 0;
}