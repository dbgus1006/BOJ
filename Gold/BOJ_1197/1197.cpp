#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;
static vector<node> edges;
static vector<node> mst;
static int V, E, result = 0;
static vector<int> parent;

// 노드의 루트를 찾는 함수
int find_root(int v) {
	if (parent[v] == v) {
		return parent[v];
	}
	return find_root(parent[v]);
}

// 사이클이 발생하지 않은 간선이 선택되어 두 노드의 루트가 같도록 갱신한다.
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

	cin >> V >> E;

	parent.resize(V + 1);

	// 각 노드의 부모 초기값은 자신
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	// 가중치, 노드A, 노드B로 구성된 간선
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back(node(c, make_pair(a, b)));
	}

	// 최소 가중치를 찾기 위해 가중치를 오름차순으로 정렬
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		node now = edges[i];

		// 현재 간선의 두 정점 a, b
		int a = now.second.first;
		int b = now.second.second;

		// 루트가 같다면 (사이클이 발생) 현재 간선을 선택하지 않는다.
		if (find_root(a) == find_root(b)) {
			continue;
		}

		// 사이클이 발생하지 않으면 mst (최소 스패닝 트리)에 삽입하고
		mst.push_back(now);

		// 해당하는 두 노드를 같은 집합 (스패닝 트리)으로 묶는다.
		union_root(a, b);

		// 스패닝 트리는 모든 노드를 사이클 없이 잇기 때문에 간선의 개수는 노드 -1
		if (mst.size() == V - 1) {
			break;
		}
	}

	// 최소 스패닝 트리의 가중치를 구한다.
	for (int i = 0; i < mst.size(); i++) {
		result += mst[i].first;
	}

	cout << result;

	return 0;
}