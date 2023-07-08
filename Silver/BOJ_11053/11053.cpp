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

	int N = 0;

	cin >> N;

	vector<int> dp(N + 1);
	vector<int> v(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	int result = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
				if (dp[i] > result)
				{
					result = dp[i];
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}