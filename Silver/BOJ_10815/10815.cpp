#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> map;
static int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		map.insert(make_pair(num, true));
	}

	cin >> M;

	for (int i = 0; i < M - 1; i++) {
		int num;
		cin >> num;

		if (map[num]) {
			cout << map[num] << " ";
		}
		else {
			cout << "0 ";
		}
	}
	int num;
	cin >> num;
	if (map[num]) {
		cout << map[num];
	}
	else {
		cout << "0";
	}

	return 0;
}