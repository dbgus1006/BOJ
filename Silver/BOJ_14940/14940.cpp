#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int _map[1000][1000] = { 0 };
static bool visited[1000][1000] = { false };

typedef pair<int, int> Node;

static queue<Node> q;
static int n, m;

void BFS(int x, int y)
{
	q.push(Node(x, y));
	visited[x][y] = true;
	_map[x][y] = 0;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		if (now.first + 1 < n && 
			!visited[now.first + 1][now.second] &&
			_map[now.first + 1][now.second] != 0)
		{
			q.push(Node(now.first + 1, now.second));
			visited[now.first + 1][now.second] = true;
			_map[now.first + 1][now.second] = _map[now.first][now.second] + 1;
		}
		if (now.first - 1 > -1 &&
			!visited[now.first - 1][now.second] &&
			_map[now.first - 1][now.second] != 0)
		{
			q.push(Node(now.first - 1, now.second));
			visited[now.first - 1][now.second] = true;
			_map[now.first - 1][now.second] = _map[now.first][now.second] + 1;
		}
		if (now.second - 1 > -1 &&
			!visited[now.first][now.second - 1] &&
			_map[now.first][now.second - 1] != 0)
		{
			q.push(Node(now.first, now.second - 1));
			visited[now.first][now.second - 1] = true;
			_map[now.first][now.second - 1] = _map[now.first][now.second] + 1;
		}
		if (now.second + 1 < m &&
			!visited[now.first][now.second + 1] &&
			_map[now.first][now.second + 1] != 0)
		{
			q.push(Node(now.first, now.second + 1));
			visited[now.first][now.second + 1] = true;
			_map[now.first][now.second + 1] = _map[now.first][now.second] + 1;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int ex, ey;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> _map[i][j];
			if (_map[i][j] == 2)
			{
				ex = i;
				ey = j;
			}
		}
	}

	BFS(ex, ey);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && !_map[i][j])
			{
				cout << "0 ";
			}
			//else if (!visited[i][j])
			//{
			//	cout << "-1 ";
			//}
			else
			{
				cout << _map[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}