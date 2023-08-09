#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int dp[500][500] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}

	int res = dp[0][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][0];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}

			res = max(res, dp[i][j]);
		}
	}

	cout << res << "\n";

	return 0;
}