#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v;
	string T;
	getline(cin, T);
	istringstream iss(T);
	string str_buf;
	while (getline(iss, str_buf, ' ')) {
		v.push_back(str_buf);
	}

	int result = 0;

	for (int i = 0; i < v[0].length(); i++) {
		if (v[0][i] != v[1][i]) {
			result++;
		}
	}

	for (int i = 0; i < v[1].length() - v[0].length() + 1; i++) {
		string AA = v[1].substr(0, i) + v[0] + v[1].substr(v[0].length() + i, v[1].length() - (v[0].length() + i));

		int diff = 0;
		for (int j = 0; j < AA.length(); j++) {
			if (AA[j] != v[1][j]) {
				diff++;
			}
		}
		result = min(result, diff);
	}

	cout << result;

	return 0;
}