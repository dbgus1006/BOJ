#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;

typedef pair<int, int> node;
typedef pair<node, node> location;
static int N, countOfStudent, satisfaction = 0;
static int classroom[21][21] = { 0, };
static vector<vector<int>> likeStudent;
static vector<int> turn;
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

// location(firstNode(like, blank), secondNode(y, x))
// firstNode - DESC, secondNode - ASC
struct cmp {
	bool operator()(location a, location b) {
		if (a.first.first == b.first.first) {
			if (a.first.second == b.first.second) {
				if (a.second.first == b.second.first) {
					return a.second.second > b.second.second;
				}
				return a.second.first > b.second.first;
			}
			return a.first.second < b.first.second;
		}
		return a.first.first < b.first.first;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	countOfStudent = N * N;
	turn.resize(countOfStudent);
	likeStudent.resize(countOfStudent + 1);

	for (int i = 0; i < countOfStudent; i++) {
		cin >> turn[i];

		likeStudent[turn[i]].resize(4);

		for (int j = 0; j < 4; j++) {
			cin >> likeStudent[turn[i]][j];
		}
	}

	for (int idx = 0; idx < countOfStudent; idx++) {
		priority_queue<location, vector<location>, cmp> pq;

		int student = turn[idx];

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (classroom[i][j] == 0) {
					int like = 0;
					int blank = 0;

					for (int k = 0; k < 4; k++) {
						int next_y = i + yy[k];
						int next_x = j + xx[k];

						if (next_y >= 1 && next_y <= N && next_x >= 1 && next_x <= N) {
							if (classroom[next_y][next_x] == 0) {
								blank++;
							}
							else {
								for (int ls = 0; ls < 4; ls++) {
									if (likeStudent[student][ls] == classroom[next_y][next_x]) {
										like++;
										break;
									}
								}
							}
						}
					}

					pq.push(location(node(like, blank), node(i, j)));
				}
			}
		}

		classroom[pq.top().second.first][pq.top().second.second] = student;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int like = 0;

			for (int k = 0; k < 4; k++) {
				int next_y = i + yy[k];
				int next_x = j + xx[k];

				if (next_y >= 1 && next_y <= N && next_x >= 1 && next_x <= N) {
					for (int ls = 0; ls < 4; ls++) {
						if (likeStudent[classroom[i][j]][ls] == classroom[next_y][next_x]) {
							like++;
							break;
						}
					}
				}
			}

			if (like != 0) {
				satisfaction += (pow(10, like - 1));
			}
		}
	}

	cout << satisfaction << "\n";

	return 0;
}