#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <tuple>
#define pos x + mx[i]][y + my[i]
using namespace std;

typedef tuple<bool, int, int> node;
static int iMap[1002][1002];
static int dist[2][1001][1001];
static int mx[4] = { 1, -1, 0, 0 };
static int my[4] = { 0, 0, 1, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	cin.ignore();

	fill_n(&dist[0][0][0], 2 * 1001 * 1001, INT_MAX);
	fill_n(&iMap[0][0], 1002 * 1002, -1);

	for (int i = 1; i <= N; i++)
	{
		string irow;

		getline(cin, irow);

		for (int j = 1; j <= M; j++)
		{
			char c = irow.at(j - 1);
			iMap[i][j] = c - '0';
		}
	}

	queue<node> q;
	q.push(node(false, 1, 1));
	dist[0][1][1] = 1;
	
	while (!q.empty())
	{
		bool isBust = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (iMap[pos] > -1)
			{
				if (isBust)
				{
					if (iMap[pos] == 0)
					{
						if (dist[1][pos] > dist[1][x][y] + 1)
						{
							dist[1][pos] = dist[1][x][y] + 1;
							q.push(node(isBust, x + mx[i], y + my[i]));
						}
					}
				}
				else
				{
					if (iMap[pos] == 0)
					{
						if (dist[0][pos] > dist[0][x][y] + 1)
						{
							dist[0][pos] = dist[0][x][y] + 1;
							q.push(node(isBust, x + mx[i], y + my[i]));
						}
					}
					else if (iMap[pos] == 1)
					{
						if (dist[1][pos] > dist[0][x][y] + 1)
						{
							dist[1][pos] = dist[0][x][y] + 1;
							q.push(node(true, x + mx[i], y + my[i]));
						}
					}
				}
			}
		}
	}

	if (min(dist[0][N][M], dist[1][N][M]) == INT_MAX)
	{
		cout << "-1\n";
	}
	else
	{
		cout << min(dist[0][N][M], dist[1][N][M]);
	}

	return 0;
}