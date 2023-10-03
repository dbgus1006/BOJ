#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

typedef pair<int, int> Node;
static int dp[1002][1002];
static vector<Node> v_list;
static int N, W;

int Calc_Distance(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

int Total_Distance(int p1, int p2)
{
	if (p1 == W || p2 == W)
	{
		return 0;
	}

	if (dp[p1][p2] != -1)
	{
		return dp[p1][p2];
	}

	int next = max(p1, p2) + 1;
	int dist1, dist2;

	if (p1 == 0)
	{
		dist1 = Calc_Distance(1, 1, v_list[next].first, v_list[next].second);
	}
	else
	{
		dist1 = Calc_Distance(v_list[p1].first, v_list[p1].second, v_list[next].first, v_list[next].second);
	}

	if (p2 == 0)
	{
		dist2 = Calc_Distance(N, N, v_list[next].first, v_list[next].second);
	}
	else
	{
		dist2 = Calc_Distance(v_list[p2].first, v_list[p2].second, v_list[next].first, v_list[next].second);
	}

	int res1 = dist1 + Total_Distance(next, p2);
	int res2 = dist2 + Total_Distance(p1, next);

	dp[p1][p2] = min(res1, res2);

	return dp[p1][p2];
}

void Get_Route(int p1, int p2)
{
	if (p1 == W || p2 == W)
	{
		return;
	}
	
	int next = max(p1, p2) + 1;
	int dist1, dist2;

	if (p1 == 0)
	{
		dist1 = Calc_Distance(1, 1, v_list[next].first, v_list[next].second);
	}
	else
	{
		dist1 = Calc_Distance(v_list[p1].first, v_list[p1].second, v_list[next].first, v_list[next].second);
	}

	if (p2 == 0)
	{
		dist2 = Calc_Distance(N, N, v_list[next].first, v_list[next].second);
	}
	else
	{
		dist2 = Calc_Distance(v_list[p2].first, v_list[p2].second, v_list[next].first, v_list[next].second);
	}

	if (dist1 + dp[next][p2] < dist2 + dp[p1][next])
	{
		cout << "1\n";
		Get_Route(next, p2);
	}
	else
	{
		cout << "2\n";
		Get_Route(p1, next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> W;

	memset(dp, -1, sizeof(dp));
	v_list.resize(W + 1);

	for (int w = 1; w <= W; w++)
	{
		int x, y;

		cin >> x >> y;

		v_list[w] = Node(x, y);
	}

	cout << Total_Distance(0, 0) << "\n";
	Get_Route(0, 0);

	return 0;
}