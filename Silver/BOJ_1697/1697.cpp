#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static vector<bool> visited(100001);
static queue<node> q;
static int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	int res = 0;

	q.push(node(N, 0));

	while (!q.empty())
	{
		node now = q.front();
		q.pop();

		if (now.first < 0 || now.first > 100000)
		{
			continue;
		}
		else if (visited[now.first])
		{
			continue;
		}
		else if (now.first == K)
		{
			res = now.second;
			break;
		}

		visited[now.first] = true;

		q.push(node(now.first + 1, now.second + 1));
		q.push(node(now.first - 1, now.second + 1));
		q.push(node(now.first * 2, now.second + 1));
	}

	cout << res << "\n";

	return 0;
}