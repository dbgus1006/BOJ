#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <limits.h>
#define ll long long
using namespace std;

typedef tuple<int, int, int> edge;
static vector<edge> v_list;
static vector<ll> dist;
static vector<int> money;
static int N, S, E, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S >> E >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		v_list.push_back(edge(a, b, c));
	}

	dist.resize(N);
	fill(dist.begin(), dist.end(), LLONG_MIN);
	money.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
	}

	dist[S] = money[S];

	for (int i = 0; i <= N + 50; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int st = get<0>(v_list[j]);
			int ed = get<1>(v_list[j]);
			int wg = get<2>(v_list[j]);

			if (dist[st] == LLONG_MAX)
			{
				dist[ed] = LLONG_MAX;
			}
			else if (dist[st] != LLONG_MIN && dist[ed] < dist[st] - wg + money[ed])
			{
				dist[ed] = dist[st] - wg + money[ed];

				if (i >= N - 1)
				{
					dist[ed] = LLONG_MAX;
				}
			}
		}
	}

	if (dist[E] == LLONG_MIN)
	{
		cout << "gg\n";
	}
	else if (dist[E] == LLONG_MAX)
	{
		cout << "Gee\n";
	}
	else
	{
		cout << dist[E] << "\n";
	}

	return 0;
}