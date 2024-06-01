#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

typedef pair<int, int> node;
static int map[51][51] = { 0, };
static int virus_map[51][51];
static bool visited[51][51] = { false, };
static bool virus_visited[51][51];
static int xx[4] = { 1, -1, 0, 0 };
static int yy[4] = { 0, 0, 1, -1 };
static vector<node> virus;
static vector<node> virus_enable_location;
static int N = 0, M = 0;
static int min_time = 3000;
void BFS();

void DFS(int depth, int idx) {

	// depth : count of virus
	if (depth < M) {
		for (; idx < virus_enable_location.size(); idx++) {
			if (virus.back().first == virus_enable_location[idx].first && virus.back().second == virus_enable_location[idx].second) {
				continue;
			}
			virus.push_back(virus_enable_location[idx]);
			DFS(depth + 1, idx);
		}
	}
	
	if (depth == M) {
		BFS();
	}
	virus.pop_back();
}

void BFS() {
	copy(&map[0][0], &map[50][51], &virus_map[0][0]);
	copy(&visited[0][0], &visited[50][51], &virus_visited[0][0]);

	priority_queue<pair<int, node>, vector<pair<int, node>>, greater<pair<int, node>>> pq;
	int clear_time = 0;

	for (int i = 0; i < M; i++) {
		virus_map[virus[i].first][virus[i].second] = 0;
		pq.push(make_pair(0, node(virus[i].first, virus[i].second)));
	}

	while (!pq.empty()) {
		int sec = pq.top().first;
		int now_y = pq.top().second.first;
		int now_x = pq.top().second.second;
		pq.pop();

		if (virus_visited[now_y][now_x] == true) {
			continue;
		}
		virus_visited[now_y][now_x] = true;
		clear_time = max(clear_time, sec);

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + yy[i];
			int next_x = now_x + xx[i];

			if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N) {
				if (virus_visited[next_y][next_x] == false) {
					if (virus_map[next_y][next_x] != -1) {
						pq.push(make_pair(sec + 1, node(next_y, next_x)));
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (virus_visited[i][j] == false) {
				return;
			}
		}
	}

	min_time = min(min_time, clear_time);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				map[i][j] = -1;
				visited[i][j] = true;
			}
			else if (map[i][j] == 2) {
				virus_enable_location.push_back(node(i, j));
				map[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < virus_enable_location.size(); i++) {
		virus.push_back(node(virus_enable_location[i].first, virus_enable_location[i].second));
		DFS(1, i);
	}
	
	if (min_time == 3000) {
		cout << "-1\n";
	}
	else {
		cout << min_time << "\n";
	}

	return 0;
}