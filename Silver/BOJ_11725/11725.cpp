#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> v_list;
static int parent[100001];
static bool visited[100001] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;
	v_list.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		v_list[a].push_back(b);
		v_list[b].push_back(a);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (!visited[now])
		{
			visited[now] = true;

			for (int next : v_list[now])
			{
				q.push(next);
				if (!visited[next])
				{
					parent[next] = now;
				}
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}