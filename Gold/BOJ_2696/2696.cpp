#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, M;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		priority_queue<int, vector<int>, greater<int>> min_pq;
		priority_queue<int, vector<int>, less<int>> max_pq;

		cin >> M;

		if (M % 2 == 0)
		{
			cout << M / 2 << "\n";
		}
		else
		{
			cout << M / 2 + 1 << "\n";
		}

		for (int i = 1; i <= M; i++)
		{
			int a;

			cin >> a;

			if (i % 2 == 0)
			{
				min_pq.push(a);
			}
			else
			{
				max_pq.push(a);
			}

			if (!max_pq.empty() && !min_pq.empty())
			{
				if (min_pq.top() < max_pq.top())
				{
					min_pq.push(max_pq.top());
					max_pq.pop();
					max_pq.push(min_pq.top());
					min_pq.pop();
				}
			}

			if (!(i % 2 == 0))
			{
				cout << max_pq.top() << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}