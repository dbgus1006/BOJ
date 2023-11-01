#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N, M, st, ed;
static vector<vector<int>> vc;
static bool visited[101] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> st >> ed >> M;

	vc.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	queue<node> q;
	q.push(node(0, st));

	while (!q.empty())
	{
		int now = q.front().second;
		int cnt = q.front().first;
		q.pop();

		if (visited[now])
		{
			continue;
		}

		visited[now] = true;

		if (now == ed)
		{
			cout << cnt << "\n";
			break;
		}

		for (int i : vc[now])
		{
			if (!visited[i])
			{
				q.push(node(cnt + 1, i));
			}
		}
	}

	if (!visited[ed])
	{
		cout << "-1\n";
	}

	return 0;
}