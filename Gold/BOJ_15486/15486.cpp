#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> dp(1500001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	int current_max = 0;

	for (int i = 1; i <= N; i++)
	{
		int t, p;

		cin >> t >> p;

		current_max = max(dp[i], current_max);

		if (i + t > N + 1)
		{
			continue;
		}

		dp[i + t] = max(current_max + p, dp[i + t]);
	}

	cout << current_max << "\n";

	return 0;
}