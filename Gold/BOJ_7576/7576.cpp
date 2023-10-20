#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> node;
static int N, M, res = 0;
static int visited[1000][1000] = { 0, };
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	priority_queue<node, vector<node>, greater<node>> pq;

	for (int i = 0; i < N; i++)
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

		for (int i = 0; i < 4; i++)
		{
			if (now_x + xx[i] >= 0 && now_x + xx[i] < M && now_y + yy[i] >= 0 && now_y + yy[i] < N)
			{
				if (visited[now_y + yy[i]][now_x + xx[i]] != -1 && visited[now_y + yy[i]][now_x + xx[i]] == 0)
				{
					pq.push(node(now_day + 1, now_y + yy[i], now_x + xx[i]));
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
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