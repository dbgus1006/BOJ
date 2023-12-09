#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
using namespace std;

static string str1, str2;
static int dp[1001][1001] = { 0, };
static stack<char> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, str1);
	getline(cin, str2);

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[str1.length()][str2.length()] << "\n";

	int fixed_col = str2.length();
	for (int i = str1.length(); i > 0; i--) {
		for (int j = fixed_col; j > 0; j--) {
			if (dp[i][j] == dp[i - 1][j]) {
				fixed_col = j;
				break;
			}
			else if (dp[i][j] == dp[i][j - 1]) {
				continue;
			}
			else {
				result.push(str1[i - 1]);
			}
		}
	}

	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}