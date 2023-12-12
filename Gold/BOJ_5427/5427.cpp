#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, pair<int, int>> node;
static int T, w, h;
static char map[1001][1001];
static bool visited[1001][1001] = { false, };
static int xx[4] = { 1, -1, 0, 0 };
static int yy[4] = { 0, 0, 1, -1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> w >> h;
		cin.ignore();
		
		fill(&map[0][0], &map[1000][1001], '#');

		priority_queue<node, vector<node>, greater<node>> fire;
		priority_queue<node, vector<node>, greater<node>> sg;

		for (int H = 0; H < h; H++) {
			string str;
			getline(cin, str);

			for (int W = 0; W < w; W++) {
				map[H][W] = str[W];

				if (str[W] == '@') {
					map[H][W] = '.';
					sg.push(node(0, make_pair(H, W)));
				}
				if (str[W] == '*') {
					map[H][W] = '.';
					fire.push(node(0, make_pair(H, W)));
				}
			}
		}

		int result = -1;
		int cnt = 0;

		while (!sg.empty()) {
			while (!fire.empty() && fire.top().first == cnt) {
				int nowFire_time = fire.top().first;
				int nowFire_y = fire.top().second.first;
				int nowFire_x = fire.top().second.second;
				fire.pop();

				if (map[nowFire_y][nowFire_x] == '*') {
					continue;
				}
				map[nowFire_y][nowFire_x] = '*';

				for (int i = 0; i < 4; i++) {
					int nextFire_y = nowFire_y + yy[i];
					int nextFire_x = nowFire_x + xx[i];

					if (nextFire_y >= 0 && nextFire_x >= 0 && nextFire_y < h && nextFire_x < w) {
						if (map[nextFire_y][nextFire_x] == '.') {
							fire.push(node(nowFire_time + 1, make_pair(nextFire_y, nextFire_x)));
						}
					}
				}
			}

			while (!sg.empty() && sg.top().first == cnt) {
				int now_time = sg.top().first;
				int now_y = sg.top().second.first;
				int now_x = sg.top().second.second;
				sg.pop();

				if (now_y <= 0 || now_x <= 0 || now_y >= h - 1 || now_x >= w - 1) {
					result = now_time + 1;
					break;
				}

				if (visited[now_y][now_x] == true) {
					continue;
				}
				visited[now_y][now_x] = true;

				for (int i = 0; i < 4; i++) {
					int next_y = now_y + yy[i];
					int next_x = now_x + xx[i];

					if (next_y >= 0 && next_x >= 0 && next_y < h && next_x < w) {
						if (map[next_y][next_x] == '.') {
							bool check_fire = false;

							for (int j = 0; j < 4; j++) {
								int check_fire_y = next_y + yy[j];
								int check_fire_x = next_x + xx[j];

								if (check_fire_y >= 0 && check_fire_x >= 0 && check_fire_y < h && check_fire_x < w) {
									if (map[check_fire_y][check_fire_x] == '*') {
										check_fire = true;
										break;
									}
								}
							}

							if (check_fire == true) {
								continue;
							}

							sg.push(node(now_time + 1, make_pair(next_y, next_x)));
						}
					}
				}
			}
			cnt++;

			if (result != -1) {
				break;
			}
		}

		if (result == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << result << "\n";
		}

		fill(&visited[0][0], &visited[1000][1001], false);

	}

	return 0;
}