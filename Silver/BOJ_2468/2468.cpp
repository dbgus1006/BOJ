#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N, res = 1, max_h = 0;
static int map[101][101] = { 0, };
static bool visited[101][101] = { false, };
static int xx[4] = { 1, -1, 0, 0 };
static int yy[4] = { 0, 0, 1, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > max_h)
			{
				max_h = map[i][j];
			}
		}
	}

	for (int i = 0; i <= max_h; i++)
	{
		int cnt = 0;
		queue<node> q;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (!visited[y][x] && map[y][x] > i)
				{
					cnt++;
					q.push(node(y, x));
				}

				while (!q.empty())
				{
					int now_y = q.front().first;
					int now_x = q.front().second;
					q.pop();

					if (visited[now_y][now_x])
					{
						continue;
					}

					visited[now_y][now_x] = true;

					for (int p = 0; p < 4; p++)
					{
						int next_y = now_y + yy[p];
						int next_x = now_x + xx[p];

						if (next_y >= 0 && next_y < N && next_x >= 0 && next_y < N)
						{
							if (map[next_y][next_x] > i)
							{
								if (!visited[next_y][next_x])
								{
									q.push(node(next_y, next_x));
								}
							}
						}
					}
				}
			}
		}

		res = max(res, cnt);
		fill(&visited[0][0], &visited[100][101], false);
	}

	cout << res << "\n";

	return 0;
}