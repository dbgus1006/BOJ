#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;
static vector<node> vc;
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		vc.push_back(node(y, x));
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < N; i++) {
		cout << vc[i].second << " " << vc[i].first << "\n";
	}

	return 0;
}