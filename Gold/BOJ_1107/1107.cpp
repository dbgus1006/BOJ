#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static int channel[1000000] = { 0, };
static int N, M, minResult = 98765432;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		for (int j = 0; j < 1000000; j++) {
			if (to_string(j).find(num + '0') != string::npos) {
				channel[j] = -1;
			}
		}
	}

	for (int i = 0; i < 1000000; i++) {
		if (channel[i] != -1) {
			int cnt = to_string(i).length() + (abs(N - i));
			

			minResult = min(cnt, minResult);
		}
	}

	cout << min(abs(N - 100),minResult) << "\n";

	return 0;
}