#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static vector<string> map;
static int N, M, result = 64;
static char start[2] = { 'W', 'B' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin.ignore();

	map.resize(N);
	for (int i = 0; i < N; i++) {
		getline(cin, map[i]);
	}

	for (int y = 0; y <= N - 8; y++) {
		for (int x = 0; x <= M - 8; x++) {

			for (char st : start) {

				int cnt = 0;

				for (int i = y; i < y + 8; i++) {
					for (int j = x; j < x + 8; j++) {

						if (i % 2 == 0) {
							if (j % 2 == 0) {
								if (map[i][j] != st) {
									cnt++;
								}
							}
							else {
								if (map[i][j] == st) {
									cnt++;
								}
							}
						}
						else {
							if (j % 2 == 0) {
								if (map[i][j] == st) {
									cnt++;
								}
							}
							else {
								if (map[i][j] != st) {
									cnt++;
								}
							}
						}
					}
				}

				result = min(result, cnt);
			}
		}
	}

	cout << result;

	return 0;
}