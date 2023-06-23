#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static int N, M, S, E;
vector<vector<edge>> vlist;
vector<bool> visited;
vector<int> dist;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vlist.resize(N + 1);
	visited.resize(N + 1);
	dist.resize(N + 1);

	fill(visited.begin(), visited.end(), false);
	fill(dist.begin(), dist.end(), INT_MAX);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		vlist[a].push_back(make_pair(b, c));
	}

	cin >> S >> E;

	pq.push(make_pair(0, S));
	dist[S] = 0;

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
			}

			pq.push(make_pair(dist[next], next));
		}
	}

	cout << dist[E] << "\n";

	return 0;
}