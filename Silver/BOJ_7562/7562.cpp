#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> node;
static int T, N, res = 0;
static bool visited[301][301] = { false, };
static int yy[8] = { 2, 1, -2, -1, 2, 1, -2, -1 };
static int xx[8] = { 1, 2, 1, 2, -1, -2, -1, -2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		int st_x, st_y, ed_x, ed_y, cnt = 0;

		cin >> st_x >> st_y >> ed_x >> ed_y;

		priority_queue<node, vector<node>, greater<node>> pq;
		pq.push(node(cnt, st_y, st_x));

		while (!pq.empty())
		{
			int now_cnt = get<0>(pq.top());
			int now_y = get<1>(pq.top());
			int now_x = get<2>(pq.top());
			pq.pop();

			if (now_y == ed_y && now_x == ed_x)
			{
				res = now_cnt;
			}

			if (visited[now_y][now_x])
			{
				continue;
			}

			visited[now_y][now_x] = true;

			for (int i = 0; i < 8; i++)
			{
				int next_y = now_y + yy[i];
				int next_x = now_x + xx[i];

				if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N)
				{
					if (!visited[next_y][next_x])
					{
						pq.push(node(now_cnt + 1, next_y, next_x));
					}
				}
			}
		}

		cout << res << "\n";
		res = 0;
		fill(&visited[0][0], &visited[300][301], false);
	}

	return 0;
}