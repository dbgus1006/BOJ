#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX 987654321
using namespace std;

typedef tuple<int, int, int> node;
static vector<vector<node>> v(1001);
static priority_queue<node, vector<node>, greater<node>> pq;
static int dist[1001][1001];
static int N, M, K, S, D, tax, tax_sum = 0;

void Calc_Tax()
{
	int res = MAX;

	for (int i = 1; i < N; i++)
	{
		int cur_tax = dist[D][i] + tax_sum * i;
		res = min(cur_tax, res);
	}

	cout << res << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K >> S >> D;

	for (int i = 0; i < M; i++)
	{
		int a, b, w;

		cin >> a >> b >> w;

		v[a].push_back(node(w, 0, b));
		v[b].push_back(node(w, 0, a));
	}

	fill(&dist[0][0], &dist[1000][1001], MAX);

	dist[S][0] = 0;
	pq.push(node(0, 0, S));

	while (!pq.empty())
	{
		int now_w = get<0>(pq.top());
		int now_cnt = get<1>(pq.top());
		int now_pos = get<2>(pq.top());

		pq.pop();

		if (dist[now_pos][now_cnt] < now_w || now_cnt >= N)
		{
			continue;
		}

		for (node n : v[now_pos])
		{
			int next_w = get<0>(n);
			int next_pos = get<2>(n);

			if (dist[next_pos][now_cnt + 1] > now_w + next_w)
			{
				dist[next_pos][now_cnt + 1] = now_w + next_w;
				pq.push(node(now_w + next_w, now_cnt + 1, next_pos));
			}
		}
	}

	Calc_Tax();

	for (int i = 0; i < K; i++)
	{
		cin >> tax;
		tax_sum += tax;
		Calc_Tax();
	}

	return 0;
}