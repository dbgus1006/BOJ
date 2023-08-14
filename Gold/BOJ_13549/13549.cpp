#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static bool visited[100001] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	priority_queue<node, vector<node>, greater<node>> q;

	q.push(node(0, N));

	while (!q.empty())
	{
		node now = q.top();
		int ntime = now.first;
		int npos = now.second;
		q.pop();

		if (npos == K)
		{
			cout << ntime << "\n";
			break;
		}

		if (!visited[npos])
		{
			visited[npos] = true;

			if (npos - 1 >= 0 && !visited[npos - 1])
			{
				q.push(node(ntime + 1, npos - 1));
			}
			if (npos + 1 <= 100000 && !visited[npos + 1])
			{
				q.push(node(ntime + 1, npos + 1));
			}
			if (npos * 2 <= 100000 && !visited[npos * 2])
			{
				q.push(node(ntime, npos * 2));
			}
		}
	}

	return 0;
}