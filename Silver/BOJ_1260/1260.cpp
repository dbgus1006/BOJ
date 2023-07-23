#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> v;
static vector<bool> visited;

void DFS(int d)
{
	if (visited[d])
		return;

	cout << d << " ";

	visited[d] = true;

	for (int i : v[d])
	{
		DFS(i);
	}
}

void BFS(int b)
{
	queue<int> qe;
	qe.push(b);
	visited[b] = true;

	while (!qe.empty())
	{
		int now = qe.front();
		qe.pop();
		cout << now << " ";

		for (int i : v[now])
		{
			if (!visited[i])
			{
				visited[i] = true;
				qe.push(i);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0, S = 0;
	int result = 0;

	cin >> N >> M >> S;

	v.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i < N + 1; i++)
	{
		sort(v[i].begin(), v[i].end());
	}


	DFS(S);

	cout << "\n";

	visited = vector<bool>(N + 1, false);

	BFS(S);

	cout << "\n";

	return 0;
}