#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> v;
static vector<vector<bool>> visited;

typedef pair<int, int> Node;

static queue<Node> q;

void BFS(int N, int M)
{
	int x = 0, y = 0;

	visited[x][y] = true;
	q.push(Node(x, y));

	while (!visited[N - 1][M - 1])
	{
		Node now;
		now = q.front();
		q.pop();
		
		if (now.second < M - 1 &&
			!visited[now.first][now.second + 1] &&
			v[now.first][now.second + 1] != 0)
		{
			q.push(Node(now.first, now.second + 1));
			v[now.first][now.second + 1] += v[now.first][now.second];
			visited[now.first][now.second + 1] = true;
		}
		if (now.first < N - 1 &&
			!visited[now.first + 1][now.second] &&
			v[now.first + 1][now.second] != 0)
		{
			q.push(Node(now.first + 1, now.second));
			v[now.first + 1][now.second] += v[now.first][now.second];
			visited[now.first + 1][now.second] = true;
		}
		if (now.second > 0 &&
			!visited[now.first][now.second - 1] &&
			v[now.first][now.second - 1] != 0)
		{
			q.push(Node(now.first, now.second - 1));
			v[now.first][now.second - 1] += v[now.first][now.second];
			visited[now.first][now.second - 1] = true;
		}
		if (now.first > 0 &&
			!visited[now.first - 1][now.second] &&
			v[now.first - 1][now.second] != 0)
		{
			q.push(Node(now.first - 1, now.second));
			v[now.first - 1][now.second] += v[now.first][now.second];
			visited[now.first - 1][now.second] = true;
		}
	}

	cout << v[N - 1][M - 1] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;

	cin >> N >> M;

	v.resize(N);
	visited.resize(N);
	fill(visited.begin(), visited.end(), vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v[i].resize(M);
		for (int j = 0; j < M; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}

	BFS(N, M);

	return 0;
}