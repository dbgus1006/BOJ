#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define INF 987654321
#define ll long long
using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> v_list;
static vector<ll> dist;
static int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	dist.resize(N + 1);
	fill(dist.begin() + 2, dist.end(), INF);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;

		cin >> A >> B >> C;

		v_list.push_back(edge(A, B, C));
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int st = get<0>(v_list[j]);
			int ed = get<1>(v_list[j]);
			int wg = get<2>(v_list[j]);

			if (dist[st] != INF && dist[ed] > dist[st] + wg)
			{
				dist[ed] = dist[st] + wg;
			}
		}
	}

	bool chk_Cycle = false;

	for (int j = 0; j < M; j++)
	{
		int st = get<0>(v_list[j]);
		int ed = get<1>(v_list[j]);
		int wg = get<2>(v_list[j]);

		if (dist[st] != INF && dist[ed] > dist[st] + wg)
		{
			chk_Cycle = true;
		}
	}

	if (!chk_Cycle)
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
			{
				cout << "-1\n";
			}
			else
			{
				cout << dist[i] << "\n";
			}
		}
	}
	else
	{
		cout << "-1\n";
	}

	return 0;
}