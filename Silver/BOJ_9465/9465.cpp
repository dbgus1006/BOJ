#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> dp(2, vector<int>(100001, 0));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> dp[i][j];
			}
		}

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = dp[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = dp[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		int res = max(dp[0][N], dp[1][N]);

		cout << res << "\n";
		fill(dp[0].begin(), dp[0].end(), 0);
		fill(dp[1].begin(), dp[1].end(), 0);
	}

	return 0;
}