#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

static ll DP[101][101] = { 0, };
static bool chk[201][201] = { false, };
static int N, M, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		chk[b + d][a + c] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		if (chk[0][i * 2 - 1])
		{
			break;
		}
			DP[0][i] = 1;
	}
	for (int i = 1; i <= M; i++)
	{
		if (chk[i * 2 - 1][0])
		{
			break;
		}
			DP[i][0] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!chk[j * 2 - 1][i * 2])
			{
				DP[j][i] += DP[j - 1][i];
			}
			if (!chk[j * 2][i * 2 - 1])
			{
				DP[j][i] += DP[j][i - 1];
			}
		}
	}

	cout << DP[M][N] << "\n";

	return 0;
}