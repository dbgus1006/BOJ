#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> v;
static vector<bool> visited;
static int result = 0;

void DFS(int a, int t)
{
	if (result)
		return;
	else
	{
		if (visited[a])
			return;

		if (t == 4)
		{
			result = 1;
			cout << result << "\n";
			return;
		}
		else
		{
			visited[a] = true;

			for (int i : v[a])
			{
				DFS(i, t + 1);
			}

			visited[a] = false;
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;

	cin >> N >> M;

	v.resize(N);

	visited = vector<bool>(N, false);
	

	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		DFS(i, 0);
	}

	if (result == 0)
		cout << result << "\n";

	return 0;
}