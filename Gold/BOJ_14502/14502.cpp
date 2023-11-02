#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N, M, maxSafeZone = 0;
static int map[9][9] = { 0, };
static int wall_map[9][9];
static bool visited[9][9] = { false, };
static vector<node> wall;
static vector<node> virus;
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };
void DFS(int depth, int y, int x);
void BFS();

void DFS(int depth, int y, int x)
{
	int i = y, j = x;

	if (depth < 3)
	{
		for (; i < N; i++)
		{
			for (; j < M; j++)
			{
				if (wall.back().first == i && wall.back().second == j)
				{
					continue;
				}
				if (map[i][j] == 0)
				{
					wall.push_back(node(i, j));
					DFS(depth + 1, i, j);
				}
			}
			j = 0;
		}
	}

	if (depth == 3)
	{
		BFS();
	}

	wall.pop_back();
}

void BFS()
{
	copy(&map[0][0], &map[8][9], &wall_map[0][0]);
	for (int i = 0; i < 3; i++)
	{
		int y = wall[i].first;
		int x = wall[i].second;

		wall_map[y][x]++;
	}

	queue<node> q;

	for (int i = 0; i < virus.size(); i++)
	{
		q.push(node(virus[i].first, virus[i].second));
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
		wall_map[now_y][now_x] = 2;

		for (int i = 0; i < 4; i++)
		{
			int next_y = now_y + yy[i];
			int next_x = now_x + xx[i];

			if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M)
			{
				if (wall_map[next_y][next_x] == 0)
				{
					if (!visited[next_y][next_x])
					{
						q.push(node(next_y, next_x));
					}
				}
			}
		}
	}

	fill(&visited[0][0], &visited[8][9], false);
	int countSafeZone = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (wall_map[i][j] == 0)
			{
				countSafeZone++;
			}
		}
	}

	maxSafeZone = max(maxSafeZone, countSafeZone);
}

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

			if (map[i][j] == 2)
			{
				virus.push_back(node(i, j));
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && wall.empty())
			{
				wall.push_back(node(i, j));
				DFS(1, i, j);
			}
		}
	}

	cout << maxSafeZone << "\n";

	return 0;
}