#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

typedef tuple<int, int, int> node;
static int map[1003][1003];
static int dist[11][1003][1003] = { 0, };
static int N, M, K;
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	cin.ignore();

	for (int i = 1; i <= N; i++) {
		string line;
		getline(cin, line);

		for (int j = 1; j <= M; j++) {
			map[i][j] = line[j - 1] - '0';
		}
	}

	queue<node> pq;
	pq.push(node(0, 1, 1));
	dist[0][1][1] = 1;
	int minDist = -1;

	while (!pq.empty()) {
		int countBust = get<0>(pq.front());
		int now_y = get<1>(pq.front());
		int now_x = get<2>(pq.front());
		pq.pop();

		if (now_y == N && now_x == M) {
			minDist = dist[countBust][now_y][now_x];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + yy[i];
			int next_x = now_x + xx[i];

			if (next_y >= 1 && next_y <= N && next_x >= 1 && next_x <= M) {
				if (map[next_y][next_x] == 0) {
					if (dist[countBust][next_y][next_x] == 0) {
						pq.push(node(countBust, next_y, next_x));
						dist[countBust][next_y][next_x] = dist[countBust][now_y][now_x] + 1;
					}
				}
				else {
					if (countBust < K) {
						if (dist[countBust + 1][next_y][next_x] == 0) {
							pq.push(node(countBust + 1, next_y, next_x));
							dist[countBust + 1][next_y][next_x] = dist[countBust][now_y][now_x] + 1;
						}
					}
				}
			}
		}
	}

	cout << minDist << "\n";

	return 0;
}