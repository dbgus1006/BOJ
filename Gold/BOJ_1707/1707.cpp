#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> v;
static vector<int> visited;
static int chk = 0;
static int K, V, E;

void DFS(int node, int bf_set)
{
	if (visited[node] == bf_set)
	{
		chk = 1;
		return;
	}
	else if (visited[node] != -1)
	{
		return;
	}

	if (visited[node] == -1)
	{
		if (bf_set == 0)
		{
			visited[node] = 1;
		}
		else
		{
			visited[node] = 0;
		}
	}

	for (int i : v[node])
	{
		DFS(i, visited[node]);
		if (chk == 1)
		{
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;

		v.clear();
		v.resize(V + 1);
		visited.resize(V + 1);
		fill(visited.begin(), visited.end(), -1);

		for (int j = 0; j < E; j++)
		{
			int a, b;

			cin >> a >> b;

			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int k = 1; k <= V; k++)
		{
			DFS(k, -2);
			if (chk == 1)
			{
				break;
			}
		}

		if (chk == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
			chk = 0;
		}
	}

	return 0;
}