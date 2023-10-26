#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N;
static char map[101][101];
static bool visited[101][101] = { false, };
static int RGBXB[5] = { 0, };
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };


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
		}
	}

	queue<node> q;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				q.push(node(i, j));

				if (map[i][j] == 'R')
				{
					RGBXB[0]++;
				}
				else if (map[i][j] == 'G')
				{
					RGBXB[1]++;
				}
				else
				{
					RGBXB[2]++;
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
							if (map[now_y][now_x] == map[next_y][next_x])
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
	}

	fill(&visited[0][0], &visited[100][101], false);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 'B')
			{
				map[i][j] = 'X';
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				q.push(node(i, j));

				if (map[i][j] == 'X')
				{
					RGBXB[3]++;
				}
				else
				{
					RGBXB[4]++;
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
							if (map[now_y][now_x] == map[next_y][next_x])
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
	}

	cout << RGBXB[0] + RGBXB[1] + RGBXB[2] << " " << RGBXB[3] + RGBXB[4] << "\n";

	return 0;
}