#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static priority_queue<node, vector<node>, greater<node>> pq;
static int N, L, result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pq.push(node(a, b));
	}

	int over_plank_position = 0;

	while (!pq.empty()) {
		int start = pq.top().first;
		int end = pq.top().second;
		pq.pop();

		int pool_width = end - start;

		if (start <= over_plank_position - 1) {
			pool_width -= (over_plank_position - start);
		}

		if (pool_width <= 0) {
			continue;
		}

		result += pool_width / L;
		pool_width %= L;

		if (pool_width != 0) {
			result++;
			over_plank_position = end + (L - pool_width);
		}

	}

	cout << result << "\n";

	return 0;
}