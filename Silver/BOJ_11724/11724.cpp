#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> vList;
static vector<bool> visited;

void DFS(int vNode)
{
	if (visited[vNode])
		return;

	visited[vNode] = true;

	for (int i : vList[vNode])
	{
		if (visited[i] == false)
			DFS(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	int result = 0;

	cin >> N >> M;

	vList.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	int u, v;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		vList[u].push_back(v);
		vList[v].push_back(u);
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (!visited[i])
		{
			++result;
			DFS(i);
		}
	}

	cout << result << "\n";

	return 0;
}