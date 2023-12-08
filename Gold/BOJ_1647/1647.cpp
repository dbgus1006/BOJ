#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> edge;
static vector<edge> mst;
static vector<edge> edges;
static int N, M, result = 0;
static vector<int> parent;

int find_root(int x) {
	if (parent[x] == x) {
		return parent[x];
	}
	return parent[x] = find_root(parent[x]);
}

void union_root(int a, int b) {
	int A = find_root(a);
	int B = find_root(b);

	if (A != B) {
		parent[B] = A;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	if (N == 2) {
		cout << result;
		return 0;
	}

	parent.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back(edge(c, make_pair(a, b)));
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		edge now = edges[i];

		int a = now.second.first;
		int b = now.second.second;

		if (find_root(a) == find_root(b)) {
			continue;
		}

		mst.push_back(now);
		union_root(a, b);

		if (mst.size() == N - 2) {
			break;
		}
	}

	for (int i = 0; i < mst.size(); i++) {
		result += mst[i].first;
	}

	cout << result;

	return 0;
}