#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> Node;
static int N, M, K;
static int W[1001][1001];
static priority_queue<int, vector<int>> distQ[1001];
static priority_queue<Node, vector<Node>, greater<Node>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		W[a][b] = c;
	}

	pq.push(Node(0, 1));
	distQ[1].push(0);

	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();

		for (int i = 1; i <= N; i++)
		{
			if (W[now.second][i] != 0)
			{
				if (distQ[i].size() < K)
				{
					distQ[i].push(now.first + W[now.second][i]);
					pq.push(Node(now.first + W[now.second][i], i));
				}
				else if (distQ[i].top() > now.first + W[now.second][i])
				{
					distQ[i].pop();
					distQ[i].push(now.first + W[now.second][i]);
					pq.push(Node(now.first + W[now.second][i], i));
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (distQ[i].size() == K)
		{
			cout << distQ[i].top() << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}

	return 0;
}