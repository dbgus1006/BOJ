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
static int TC, N, M, W;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	for (int tcase = 0; tcase < TC; tcase++)
	{
		cin >> N >> M >> W;

		dist.resize(N + 1);
		fill(dist.begin() + 2, dist.end(), INF);

		for (int i = 0; i < M; i++)
		{
			int A, B, C;

			cin >> A >> B >> C;

			v_list.push_back(edge(A, B, C));
			v_list.push_back(edge(B, A, C));
		}
		for (int i = 0; i < W; i++)
		{
			int A, B, C;

			cin >> A >> B >> C;

			v_list.push_back(edge(A, B, -C));
		}

		bool chk_Cycle = false;

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < v_list.size(); j++)
			{
				int st = get<0>(v_list[j]);
				int ed = get<1>(v_list[j]);
				int wg = get<2>(v_list[j]);

				if (dist[ed] > dist[st] + wg)
				{
					dist[ed] = dist[st] + wg;
				}
			}
		}

		for (int j = 0; j < v_list.size(); j++)
		{
			int st = get<0>(v_list[j]);
			int ed = get<1>(v_list[j]);
			int wg = get<2>(v_list[j]);

			if (dist[ed] > dist[st] + wg)
			{
				chk_Cycle = true;
			}
		}

		if (!chk_Cycle)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}

		v_list.clear();
		dist.clear();
	}

	return 0;
}