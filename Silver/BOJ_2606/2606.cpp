#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N, M, res = 0;
static vector<vector<int>> vc;
static bool visited[101] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vc.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (visited[now])
		{
			continue;
		}

		visited[now] = true;

		for (int idx : vc[now])
		{
			q.push(idx);
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (visited[i])
		{
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}