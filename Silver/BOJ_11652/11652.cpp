#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

static unordered_map<string, int> map;
static int N;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		if (a.first[0] == '-') {
			if (b.first[0] == '-') {
				if (a.first.size() > b.first.size()) {
					return true;
				}
				else if (a.first.size() < b.first.size()) {
					return false;
				}
				else {
					if (a.first.compare(b.first) > 0) {
						return true;
					}
					return false;
				}
			}
			else {
				return true;
			}
		}
		else {
			if (b.first[0] == '-') {
				return false;
			}
			else {
				if (a.first.size() > b.first.size()) {
					return false;
				}
				else if (a.first.size() < b.first.size()) {
					return true;
				}
				else {
					if (a.first.compare(b.first) < 0) {
						return true;
					}
					return false;
				}
			}
		}
	}
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string card;
		getline(cin, card);

		if (map.find(card) == map.end()) {
			map.insert(make_pair(card, 1));
			continue;
		}
		map[card]++;
	}

	vector<pair<string, int>> vc(map.begin(), map.end());
	sort(vc.begin(), vc.end(), compare);

	cout << vc.front().first;

	return 0;
}