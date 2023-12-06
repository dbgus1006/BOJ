#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

static vector<int> Result;
static vector<int> preCount;
static vector<vector<int>> List;
static int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Result.resize(N + 1);
	preCount.resize(N + 1);
	List.resize(N + 1);

	// a가 b의 앞에 서는 관계를 그래프로 저장. 앞서는 학생이 몇명인지 preCount로 체크
	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;

		List[a].push_back(b);
		preCount[b]++;
	}

	queue<int> q;

	// 앞서는 학생이 없다면 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (preCount[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int now = q.front();
		q.pop();
		Result[i] = now;

		// 현재 줄을 선 학생의 뒤에 오는 학생들을 체크
		for (int j = 0; j < List[now].size(); j++) {
			int next = List[now][j];

			// 앞에 서야 할 학생이 나왔으므로 preCount를 -1 한다. 더 이상 앞에 서야 할 학생이 없다면 큐에 삽입
			if (--preCount[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << Result[i] << " ";
	}

	return 0;
}