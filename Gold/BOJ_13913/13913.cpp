#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define INF 987654321
using namespace std;

typedef pair<int, int> node;
static int N, K, res = INF;
static int bfs[200001];
static int path[200001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	priority_queue<node, vector<node>, greater<node>> pq;
	pq.push(node(0, N));
	fill(&bfs[0], &bfs[200000], INF);
	bfs[N] = 0;

	while (!pq.empty())
	{
		int sec = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (pos == K)
		{
			res = sec;
			break;
		}

		int move[3] = { pos - 1, pos + 1, pos * 2 };

		for (int i = 0; i < 3; i++)
		{
			if (move[i] >= 0 && move[i] <= 200000)
			{
				if (bfs[move[i]] > sec + 1)
				{
					bfs[move[i]] = sec + 1;
					pq.push(node(sec + 1, move[i]));
					path[move[i]] = pos;
				}
			}
		}
	}

	cout << res << "\n";

	int find_path = K;
	stack<int> stk;
	stk.push(find_path);

	while (true)
	{
		if (find_path == N)
		{
			break;
		}

		stk.push(path[find_path]);
		find_path = path[find_path];
	}

	while (!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}