#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	int res;

	while (!q.empty())
	{
		res = q.front();
		q.pop();
		if (q.empty())
		{
			break;
		}
		q.push(q.front());
		q.pop();
		res = q.front();
	}

	cout << res << "\n";

	return 0;
}