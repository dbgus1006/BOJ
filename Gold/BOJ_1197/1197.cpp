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

// ����� ��Ʈ�� ã�� �Լ�
int find_root(int v) {
	if (parent[v] == v) {
		return parent[v];
	}
	return find_root(parent[v]);
}

// ����Ŭ�� �߻����� ���� ������ ���õǾ� �� ����� ��Ʈ�� ������ �����Ѵ�.
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

	// �� ����� �θ� �ʱⰪ�� �ڽ�
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	// ����ġ, ���A, ���B�� ������ ����
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back(node(c, make_pair(a, b)));
	}

	// �ּ� ����ġ�� ã�� ���� ����ġ�� ������������ ����
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		node now = edges[i];

		// ���� ������ �� ���� a, b
		int a = now.second.first;
		int b = now.second.second;

		// ��Ʈ�� ���ٸ� (����Ŭ�� �߻�) ���� ������ �������� �ʴ´�.
		if (find_root(a) == find_root(b)) {
			continue;
		}

		// ����Ŭ�� �߻����� ������ mst (�ּ� ���д� Ʈ��)�� �����ϰ�
		mst.push_back(now);

		// �ش��ϴ� �� ��带 ���� ���� (���д� Ʈ��)���� ���´�.
		union_root(a, b);

		// ���д� Ʈ���� ��� ��带 ����Ŭ ���� �ձ� ������ ������ ������ ��� -1
		if (mst.size() == V - 1) {
			break;
		}
	}

	// �ּ� ���д� Ʈ���� ����ġ�� ���Ѵ�.
	for (int i = 0; i < mst.size(); i++) {
		result += mst[i].first;
	}

	cout << result;

	return 0;
}