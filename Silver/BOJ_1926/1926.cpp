#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N, M, max_cnt = 0, max_size = 0;
static int map[501][501] = { 0, };
static bool visited[501][501] = { false, };
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<node> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				q.push(node(i, j));
				max_cnt++;

				int now_size = 0;
				
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
					now_size++;

					for (int i = 0; i < 4; i++)
					{
						int next_y = now_y + yy[i];
						int next_x = now_x + xx[i];

						if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M)
						{
							if (!visited[next_y][next_x] && map[next_y][next_x] == 1)
							{
								q.push(node(next_y, next_x));
							}
						}
					}
				}

				max_size = max(max_size, now_size);
			}
		}
	}

	cout << max_cnt << "\n" << max_size << "\n";

	return 0;
}