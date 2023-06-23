#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int V, E, K;
static vector<vector<edge>> vlist;
static vector<bool> visited;
static vector<int> dist;
static priority_queue<edge, vector<edge>, greater<edge>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	dist.resize(V + 1);
	fill(dist.begin(), dist.end(), INT_MAX);
	visited.resize(V + 1);
	fill(visited.begin(), visited.end(), false);
	vlist.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vlist[u].push_back(make_pair(v, w));
	}

	pq.push(make_pair(0, K));
	dist[K] = 0;

	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();
		int now_v = now.second;

		if (visited[now_v])
		{
			continue;
		}
		visited[now_v] = true;

		for (int i = 0; i < vlist[now_v].size(); i++)
		{
			edge tmp = vlist[now_v][i];
			int next = tmp.first;
			int value = tmp.second;

			if (dist[next] > dist[now_v] + value)
			{
				dist[next] = dist[now_v] + value;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (visited[i])
		{
			cout << dist[i] << "\n";
		}
		else
		{
			cout << "INF" << "\n";
		}
	}

	return 0;
}