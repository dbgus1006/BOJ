#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static priority_queue<int, vector<int>, greater<int>> pq;
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;

		cin >> x;

		if (x == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}