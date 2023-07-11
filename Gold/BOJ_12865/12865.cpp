#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int dp[101][100001] = { 0 };
static int W[101] = { 0 };
static int V[101] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - W[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}