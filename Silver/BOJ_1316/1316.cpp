#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;

static set<char> groupWord;
static int N, result = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);

		char now = str[0];
		groupWord.insert(now);

		bool checkWord = true;

		for (int j = 1; j < str.length(); j++) {
			if (now == str[j]) {
				continue;
			}
			else if (now != str[j]) {
				if (groupWord.count(str[j])) {
					checkWord = false;
					break;
				}
				else {
					now = str[j];
					groupWord.insert(now);
				}
			}
		}

		if (checkWord == true) {
			result++;
		}

		groupWord.clear();
	}

	cout << result;

	return 0;
}