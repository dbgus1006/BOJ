#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static int N, K;
static priority_queue<node, vector<node>, greater<node>> pq;
static bool visited[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	pq.push(node(0, N));
	visited[N] = true;

	node result = make_pair(100003, 0);

	while (!pq.empty())
	{
		node now = pq.top();
		pq.pop();

		if (now.second != K)
		{
			visited[now.second] = true;
		}

		int time = now.first;
		int next[3] = { now.second - 1, now.second + 1, now.second * 2 };

		if (result.first < time)
		{
			break;
		}

		if (now.second == K)
		{
			result.first = time;
			result.second++;
		}

		for (int i : next)
		{
			if (0 <= i && i <= 100000)
			{
				if (!visited[i])
				{
					pq.push(node(time + 1, i));
				}
			}
		}

	}

	cout << result.first << "\n" << result.second << "\n";

	return 0;
}