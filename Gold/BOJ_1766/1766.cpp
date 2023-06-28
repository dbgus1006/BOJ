#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 32001

static int N, M;
static vector<int> v[MAX];
static int indegree[MAX] = { 0 };
static priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		v[A].push_back(B);
		indegree[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!indegree[i])
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int now;

		now = pq.top();
		cout << now << " ";
		pq.pop();

		for (int next : v[now])
		{
			indegree[next]--;

			if (indegree[next] == 0)
			{
				pq.push(next);
			}
		}
	}

	return 0;
}