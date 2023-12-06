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

	// a�� b�� �տ� ���� ���踦 �׷����� ����. �ռ��� �л��� ������� preCount�� üũ
	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;

		List[a].push_back(b);
		preCount[b]++;
	}

	queue<int> q;

	// �ռ��� �л��� ���ٸ� ť�� ����
	for (int i = 1; i <= N; i++) {
		if (preCount[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int now = q.front();
		q.pop();
		Result[i] = now;

		// ���� ���� �� �л��� �ڿ� ���� �л����� üũ
		for (int j = 0; j < List[now].size(); j++) {
			int next = List[now][j];

			// �տ� ���� �� �л��� �������Ƿ� preCount�� -1 �Ѵ�. �� �̻� �տ� ���� �� �л��� ���ٸ� ť�� ����
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