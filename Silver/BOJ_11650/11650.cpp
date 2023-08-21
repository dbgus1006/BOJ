#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> node;
static priority_queue<node, vector<node>, greater<node>> pq;
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;

		cin >> x >> y;

		pq.push(node(x, y));
	}

	while (!pq.empty())
	{
		node now = pq.top();
		pq.pop();

		cout << now.first << " " << now.second << "\n";
	}

	return 0;
}