#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int dp[1000][3] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = dp[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	int res = min(dp[N - 1][0], dp[N - 1][1]);
	res = min(res, dp[N - 1][2]);

	cout << res << "\n";

	return 0;
}