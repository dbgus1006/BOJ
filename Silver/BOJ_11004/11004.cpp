#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<int> vc;
static int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		vc.push_back(num);
	}

	sort(vc.begin(), vc.end());

	cout << vc[M - 1] << "\n";

	return 0;
}