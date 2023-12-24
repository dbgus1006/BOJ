#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static queue<int> q;
static int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";


	return 0;
}