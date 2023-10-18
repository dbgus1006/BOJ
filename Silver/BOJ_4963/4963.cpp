#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int w, h;
static bool map[50][50] = { 0, };
static bool visited[50][50] = { false, };
static int xx[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
static int yy[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int res = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == false && map[i][j] == 1)
				{
					res++;
					priority_queue<node> pq;

					pq.push(node(i, j));

					while (!pq.empty())
					{
						int cx = pq.top().second;
						int cy = pq.top().first;

						pq.pop();

						if (visited[cy][cx])
						{
							continue;
						}

						visited[cy][cx] = true;

						for (int k = 0; k < 8; k++)
						{
							if (cy + yy[k] >= 0 && cy + yy[k] < h && cx + xx[k] >= 0 && cx + xx[k] < w)
							{
								if (map[cy + yy[k]][cx + xx[k]] == 1 && visited[cy + yy[k]][cx + xx[k]] == false)
								{
									pq.push(node(cy + yy[k], cx + xx[k]));
								}
							}
						}
					}
				}
			}
		}

		cout << res << "\n";

		fill(&map[0][0], &map[49][50], 0);
		fill(&visited[0][0], &visited[49][50], 0);
	}

	return 0;
}