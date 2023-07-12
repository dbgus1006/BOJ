#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> v;
static vector<int> visited;
static vector<int> ans;
static queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;

	cin >> N >> M >> K >> X;

	v.resize(N + 1);
	visited.resize(N + 1);
	fill(visited.begin(), visited.end(), -1);

	for (int i = 0; i < M; i++)
	{
		int A, B;

		cin >> A >> B;

		v[A].push_back(B);
	}

	q.push(X);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		visited[now]++;

		for (int i : v[now])
		{
			if (visited[i] == -1)
			{
				q.push(i);
				visited[i] = visited[now];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K)
		{
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	if (ans.empty())
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}

	return 0;
}