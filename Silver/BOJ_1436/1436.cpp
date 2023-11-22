#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int idx = 666, cnt = 0;

	while (cnt <= N) {
		if (to_string(idx).find("666") != string::npos) {
			cnt++;
			
			if (cnt == N) {
				cout << idx;
			}
		}
		idx++;
	}

	return 0;
}