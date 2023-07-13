#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> v;
static vector<int> visited;
static vector<int> dist;
static vector<int> ans;
static queue<int> q;

static int N, M, MAX = 0;

void BFS(int node)
{
	q.push(node);
	visited[node] = 0;
	int cnt = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i : v[now])
		{
			if (visited[i] == -1)
			{
				q.push(i);
				visited[i] = cnt++;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[node] < visited[i])
		{
			dist[node] = visited[i];
		}
	}

	if (dist[node] > MAX)
	{
		MAX = dist[node];
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(N + 1);
	visited.resize(N + 1);
	dist.resize(N + 1);

	for (int i = 1; i <= M; i++)
	{
		int A, B;

		cin >> A >> B;

		v[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited.begin(), visited.end(), -1);
		BFS(i);
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX)
		{
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}