#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static int dp[1001][1001] = { 0, };
static string str1, str2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, str1);
	getline(cin, str2);

	for (int i = 1; i <= str2.size(); i++)
	{
		for (int j = 1; j <= str1.size(); j++)
		{
			if (str2[i - 1] == str1[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[str2.length()][str1.length()] << "\n";

	return 0;
}