#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

static unordered_map<int, int> card;
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
		if (card.find(num) != card.end()) {
			card[num]++;
			continue;
		}
		card.insert(make_pair(num, 1));
	}

	cin >> M;

	for (int i = 0; i < M - 1; i++) {
		int num;
		cin >> num;
		cout << card[num] << " ";
	}
	int num;
	cin >> num;
	cout << card[num];

	return 0;
}