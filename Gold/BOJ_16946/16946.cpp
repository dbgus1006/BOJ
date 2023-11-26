#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> node;
static int N, M;
static int map[1001][1001] = { 0, };
static bool visited[1001][1001] = { false, };
static vector<node> wall;
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string mapCol;
		getline(cin, mapCol);

		for (int j = 0; j < M; j++) {
			map[i][j] = mapCol[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				queue<node> q;
				q.push(node(i, j));
				int cnt = 0;

				while (!q.empty()) {
					int now_y = q.front().first;
					int now_x = q.front().second;
					q.pop();

					if (visited[now_y][now_x] == true) {
						continue;
					}
					visited[now_y][now_x] = true;
					cnt++;

					for (int k = 0; k < 4; k++) {
						int next_y = now_y + yy[k];
						int next_x = now_x + xx[k];

						if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < M) {
							if (map[next_y][next_x] == 0) {
								if (visited[next_y][next_x] == false) {
									q.push(node(next_y, next_x));									
								}
							}
							else {
								if (visited[next_y][next_x] == false) {
									wall.push_back(node(next_y, next_x));
									visited[next_y][next_x] = true;
								}
							}
						}
					}
				}

				while (!wall.empty()) {
					map[wall.back().first][wall.back().second] += cnt;
					visited[wall.back().first][wall.back().second] = false;
					wall.pop_back();
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] % 10;
		}
		cout << "\n";
	}

	return 0;
}