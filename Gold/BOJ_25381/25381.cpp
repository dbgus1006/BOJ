#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

typedef pair<char, int> node;
static string str;
static vector<node> va;
static vector<node> vb;
static int maxTime = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') {
			va.push_back(node(str[i], i));
		}
		else if (str[i] == 'B') {
			if (!vb.empty() && !va.empty()) {
				va.pop_back();
				maxTime++;
			}
			else {
				vb.push_back(node(str[i], i));
			}
		}
		else {
			if (!vb.empty()) {
				vb.pop_back();
				maxTime++;
			}
		}
	}

	if (!va.empty() && !vb.empty()) {
		if (va.front().second < vb.back().second) {
			maxTime++;
		}
	}

	cout << maxTime << "\n";

	return 0;
}