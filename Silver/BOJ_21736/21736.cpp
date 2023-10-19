#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N, M, res = 0;
static char map[601][601];
static bool visited[601][601] = { false, };
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int ix, iy;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'I')
			{
				ix = j;
				iy = i;
			}
		}
	}

	priority_queue<node> pq;
	pq.push(node(iy, ix));

	while (!pq.empty())
	{
		int cx = pq.top().second;
		int cy = pq.top().first;

		pq.pop();

		if (visited[cy][cx] == true)
		{
			continue;
		}

		visited[cy][cx] = true;

		if (map[cy][cx] == 'P')
		{
			res++;
		}

		for (int i = 0; i < 4; i++)
		{
			if (cy + yy[i] >= 0 && cy + yy[i] < N && cx + xx[i] >= 0 && cx + xx[i] < M)
			{
				if (map[cy + yy[i]][cx + xx[i]] != 'X' && visited[cy + yy[i]][cx + xx[i]] != true)
				{
					pq.push(node(cy + yy[i], cx + xx[i]));
				}
			}
		}
	}

	if (res == 0)
	{
		cout << "TT\n";
	}
	else
	{
		cout << res << "\n";
	}

	return 0;
}