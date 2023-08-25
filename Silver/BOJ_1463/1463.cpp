#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

static int dp[1000001];
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	fill(&dp[0], &dp[1000001], INF);

	dp[N] = 0;
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now % 3 == 0)
		{
			if (dp[now] + 1 < dp[now / 3])
			{
				dp[now / 3] = dp[now] + 1;
				q.push(now / 3);
			}
		}
		if (now % 2 == 0)
		{
			if (dp[now] + 1 < dp[now / 2])
			{
				dp[now / 2] = dp[now] + 1;
				q.push(now / 2);
			}
		}
		if (dp[now] + 1 < dp[now - 1])
		{
			dp[now - 1] = dp[now] + 1;
			q.push(now - 1);
		}
	}

	cout << dp[1] << "\n";

	return 0;
}