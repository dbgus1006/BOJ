#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> node;
static int N, M, H, res = 0;
static int visited[10000][100] = { 0, };
static int xx[6] = { 0, 0, 1, -1, 0, 0 };
static int yy[6] = { 1, -1, 0, 0, 0, 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	priority_queue<node, vector<node>, greater<node>> pq;
	yy[4] = N;
	yy[5] = -N;

	for (int i = 0; i < N * H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> visited[i][j];

			if (visited[i][j] == 1)
			{
				pq.push(node(0, i, j));
			}
		}
	}

	while (!pq.empty())
	{
		int now_day = get<0>(pq.top());
		int now_y = get<1>(pq.top());
		int now_x = get<2>(pq.top());
		pq.pop();

		if (visited[now_y][now_x] == 1 && now_day != 0)
		{
			continue;
		}

		visited[now_y][now_x] = 1;
		res = max(res, now_day);

		for (int i = 0; i < 6; i++)
		{
			if (i < 2)
			{
				if ((now_y + yy[i]) / N != now_y / N)
				{
					continue;
				}
			}

			if (now_y + yy[i] >= 0 && now_y + yy[i] < N * H && now_x + xx[i] >= 0 && now_x + xx[i] < M)
			{
				if (visited[now_y + yy[i]][now_x + xx[i]] == 0)
				{
					pq.push(node(now_day + 1, now_y + yy[i], now_x + xx[i]));
				}
			}
		}
	}

	for (int i = 0; i < N * H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << res << "\n";

	return 0;
}