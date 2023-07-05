#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> Node;
static vector<vector<Node>> v;
static vector<bool> visited;
static int diameter = 0;

void DFS(Node now, int wgt)
{
	if (visited[now.first])
	{
		return;
	}

	visited[now.first] = true;

	if (v[now.first].size() == 1)
	{
		if (diameter < wgt)
		{
			diameter = wgt;
			return;
		}
	}

	for (Node i : v[now.first])
	{
		DFS(i, wgt + i.second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	v.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 1; i < N; i++)
	{
		int prt, chd, wg;

		cin >> prt >> chd >> wg;

		v[prt].push_back(Node(chd, wg));
		v[chd].push_back(Node(prt, wg));
	}

	for (int i = 1; i <= N; i++)
	{
		DFS(Node(i, 0), 0);
		fill(visited.begin(), visited.end(), false);
	}

	cout << diameter << "\n";

	return 0;
}