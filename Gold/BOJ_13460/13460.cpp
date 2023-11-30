#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

typedef pair<int, int> node;
typedef tuple<node, node, int> balls;
static char map[11][11];
static int N, M;
static node redBall, blueBall;
static int yy[4] = { 0, 0, 1, -1 };
static int xx[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);

		for (int j = 0; j < M; j++) {
			map[i][j] = line[j];

			if (map[i][j] == 'R') {
				redBall = make_pair(i, j);
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				blueBall = make_pair(i, j);
				map[i][j] = '.';
			}
		}
	}

	queue<balls> q;
	q.push(balls(redBall, blueBall, 0));

	while (!q.empty()) {
		node nowRed = get<0>(q.front());
		node nowBlue = get<1>(q.front());
		int cntMove = get<2>(q.front());
		q.pop();

		if (cntMove > 10) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			node nextRed = nowRed;
			node nextBlue = nowBlue;
			int cntRed = 0, cntBlue = 0;
			bool isRedClear = false, isBlueClear = false;

			while (true) {
				if (!isRedClear) {
					if (map[nextRed.first + yy[i]][nextRed.second + xx[i]] == '.') {
						cntRed++;
						nextRed.first += yy[i];
						nextRed.second += xx[i];
					}
					else if (map[nextRed.first + yy[i]][nextRed.second + xx[i]] == 'O') {
						cntRed++;
						nextRed.first += yy[i];
						nextRed.second += xx[i];
						isRedClear = true;
					}
				}
				if (!isBlueClear) {
					if (map[nextBlue.first + yy[i]][nextBlue.second + xx[i]] == '.') {
						cntBlue++;
						nextBlue.first += yy[i];
						nextBlue.second += xx[i];
					}
					else if (map[nextBlue.first + yy[i]][nextBlue.second + xx[i]] == 'O') {
						cntBlue++;
						nextBlue.first += yy[i];
						nextBlue.second += xx[i];
						isBlueClear = true;
					}
				}

				if ((map[nextBlue.first + yy[i]][nextBlue.second + xx[i]] == '#' && map[nextRed.first + yy[i]][nextRed.second + xx[i]] == '#') ||
					(isBlueClear && map[nextRed.first + yy[i]][nextRed.second + xx[i]] == '#') ||
					(map[nextBlue.first + yy[i]][nextBlue.second + xx[i]] == '#' && isRedClear) ||
					(isRedClear && isBlueClear)) {
					break;
				}
			}

			if (nextRed == nextBlue) {
				if (cntRed > cntBlue) {
					nextRed.first -= yy[i];
					nextRed.second -= xx[i];
				}
				else if (cntRed < cntBlue) {
					nextBlue.first -= yy[i];
					nextBlue.second -= xx[i];
				}
			}

			if (!isBlueClear) {
				if (isRedClear) {
					cout << cntMove + 1;
					return 0;
				}
				q.push(balls(nextRed, nextBlue, cntMove + 1));
			}
		}
	}

	cout << "-1";

	return 0;
}