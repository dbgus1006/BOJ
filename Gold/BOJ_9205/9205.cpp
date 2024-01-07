#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//typedef pair<pair<int, int>, int> node;
typedef pair<int, int> node;
static int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {

		int n;
		cin >> n;

		vector<node> vc;
		vector<bool> visited(n);
		fill(visited.begin(), visited.end(), false);

		int xx, yy;
		cin >> xx >> yy;
		node st(xx, yy);

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vc.push_back(node(x, y));
		}

		cin >> xx >> yy;
		node ed(xx, yy);

		queue<node> q;
		q.push(st);

		bool isArrive = false;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (abs(x - ed.first) + abs(y - ed.second) <= 1000) {
				isArrive = true;
				break;
			}
			
			for (int i = 0; i < vc.size(); i++) {
				if (!visited[i]) {
					int next_x = abs(vc[i].first - x);
					int next_y = abs(vc[i].second - y);

					if (next_x + next_y <= 1000) {
						q.push(node(vc[i].first, vc[i].second));
						visited[i] = true;
					}
				}
			}
		}

		if (isArrive) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
	}

	return 0;
}