#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> v_list;
static vector<int> dist;
static vector<bool> visited;
static priority_queue<edge, vector<edge>, greater<edge>> pq;
static int N, E, v1, v2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;

	v_list.resize(N + 1);
	dist.resize(N + 1);
	fill(dist.begin(), dist.end(), INT_MAX);
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		v_list[a].push_back(edge(b, c));
		v_list[b].push_back(edge(a, c));
	}

	cin >> v1 >> v2;

	int start[2] = { v1, v2 };
	int dest[2][4];

	for (int t = 0; t < 2; t++)
	{
		pq.push(edge(0, start[t]));
		dist[start[t]] = 0;

		while (!pq.empty())
		{
			edge now = pq.top();
			pq.pop();

			if (!visited[now.second])
			{
				visited[now.second] = true;

				for (edge i : v_list[now.second])
				{
					int next = i.first;
					int value = i.second;

					if (dist[next] > dist[now.second] + value)
					{
						dist[next] = dist[now.second] + value;
						pq.push(edge(dist[next], next));
					}
				}
			}
		}

		dest[t][0] = dist[1];
		dest[t][1] = dist[v1];
		dest[t][2] = dist[v2];
		dest[t][3] = dist[N];

		fill(dist.begin(), dist.end(), INT_MAX);
		fill(visited.begin(), visited.end(), false);
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dest[i][j] == INT_MAX)
			{
				cout << "-1\n";
				return 0;
			}
		}
	}

	int res = min((dest[0][0] + dest[0][2] + dest[1][3]), (dest[1][0] + dest[1][1] + dest[0][3]));

	cout << res << "\n";

	return 0;
}