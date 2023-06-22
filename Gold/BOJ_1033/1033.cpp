#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> v[10];
bool visited[10];
long D[10];
long lcm = 1;

void DFS(int node)
{
	visited[node] = true;

	for (tuple<int, int, int> i : v[node])
	{
		int next = get<0>(i);

		if (!visited[next])
		{
			D[next] = D[node] * get<2>(i) / get<1>(i);

			DFS(next);
		}
	}
}

long gcd(long a, long b)
{
	if (b == 0)
		return a;
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		v[a].push_back(make_tuple(b, p, q));
		v[b].push_back(make_tuple(a, q, p));

		lcm *= (p * q / gcd(p, q));
	}

	D[0] = lcm;
	DFS(0);

	long mgcd = D[0];

	for (int i = 1; i < N; i++)
	{
		mgcd = gcd(mgcd, D[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << D[i] / mgcd << " ";
	}

	return 0;
}