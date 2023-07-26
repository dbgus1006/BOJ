#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 100000000
using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> v_list;
static vector<int> v_dist;
static vector<int> v_res;
static int N, M, X;
static priority_queue<edge, vector<edge>, greater<edge>> pq;

void Dijkstra(int start)
{
	v_dist[start] = 0;
	pq.push(edge(start, v_dist[start]));

	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();

		for (edge i : v_list[now.first])
		{
			int next = i.first;
			int value = i.second;

			if (v_dist[next] > v_dist[now.first] + value)
			{
				v_dist[next] = v_dist[now.first] + value;
				pq.push(edge(next, v_dist[next]));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;

	v_list.resize(N + 1);
	v_dist.resize(N + 1);
	fill(v_dist.begin(), v_dist.end(), INF);
	v_res.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int st, ed, wt;

		cin >> st >> ed >> wt;

		v_list[st].push_back(edge(ed, wt));
	}

	for (int i = 1; i <= N; i++)
	{
		Dijkstra(i);
		v_res[i] = v_dist[X];
		fill(v_dist.begin(), v_dist.end(), INF);
	}
	Dijkstra(X);

	for (int i = 1; i <= N; i++)
	{
		v_res[i] += v_dist[i];
	}

	sort(v_res.begin(), v_res.end());

	cout << v_res[N] << "\n";

	return 0;
}