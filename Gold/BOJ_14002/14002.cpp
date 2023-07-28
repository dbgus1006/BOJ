#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<int> v;
static vector<vector<int>> dp;
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N + 1);
	dp.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	int max_dp = 0, result = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && dp[i].size() <= dp[j].size())
			{
				dp[i] = dp[j];
			}
		}

		dp[i].push_back(v[i]);

		if (max_dp < dp[i].size())
		{
			max_dp = dp[i].size();
			result = i;
		}
	}

	cout << max_dp << "\n";

	for (int i : dp[result])
	{
		cout << i << " ";
	}

	return 0;
}