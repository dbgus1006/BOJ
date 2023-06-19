#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<pair<int, int>>> v;
static vector<bool> visited;
static vector<int> v_distance;

void BFS(int s)
{
	queue<pair<int, int>> qe;
	pair<int, int> now;
	qe.push(make_pair(s, 0));
	visited[s] = true;

	while (!qe.empty())
	{
		now = qe.front();
		qe.pop();

		for (pair<int, int> i : v[now.first])
		{
			if (!visited[i.first])
			{
				qe.push(i);
				v_distance[i.first] = i.second + v_distance[now.first];
				visited[i.first] = true;
			}
		}
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
	visited = vector<bool>(N + 1, false);
	v_distance = vector<int>(N + 1, 0);

	int cnt = 0;

	while (cnt != N)
	{
		int t;
		cin >> t;

		if (t > N)
			break;

		while (true)
		{
			int a, b;

			cin >> a;

			if (a == -1)
				break;

			cin >> b;

			v[t].push_back(make_pair(a, b));
		}
		++cnt;
	}

	BFS(1);

	int dm = 0, k;

	for (int i = 1; i < N + 1; i++)
	{
		if (v_distance[i] > dm)
		{
			dm = v_distance[i];
			k = i;
		}
	}

	fill(visited.begin(), visited.end(), false);
	fill(v_distance.begin(), v_distance.end(), 0);

	BFS(k);

	for (int i = 1; i < N + 1; i++)
	{
		if (v_distance[i] > dm)
		{
			dm = v_distance[i];
		}
	}

	cout << dm << "\n";

	return 0;
}