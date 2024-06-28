#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

typedef pair<int, int> node;
static int dp[3][1002][32] = { 0, };
static int T, W, result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		int plum;

		cin >> plum;

		// dp[현재 위치][초][이동 횟수]

		if (i == 1) {
			dp[1][i][0] = (plum == 1);
			dp[2][i][1] = (plum == 2);
			continue;
		}

		for (int j = 0; j <= W; j++) {
			if (j > 0) {
				// 이동한 경우, 이동하지 않은 경우
				dp[1][i][j] = max(dp[2][i - 1][j - 1], dp[1][i - 1][j]) + (plum == 1);
				dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]) + (plum == 2);
			}
			else {
				dp[1][i][0] = dp[1][i - 1][0] + (plum == 1);
			}
		}
	}

	for (int i = 0; i <= W; i++) {
		result = max(result, max(dp[1][T][i], dp[2][T][i]));
	}
	
	cout << result << "\n";

	return 0;
}