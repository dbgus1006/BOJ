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

	priority_queue<int, vector<int>, greater<int>> min_pq;
	priority_queue<int, vector<int>, less<int>> max_pq;

	int N = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
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

		if (!min_pq.empty() && !max_pq.empty())
		{
			if (min_pq.top() < max_pq.top())
			{
				min_pq.push(max_pq.top());
				max_pq.pop();
				max_pq.push(min_pq.top());
				min_pq.pop();
			}
		}

		if (i % 2 == 0)
		{
			cout << min(min_pq.top(), max_pq.top()) << "\n";
		}
		else
		{
			cout << max_pq.top() << "\n";
		}
	}

	return 0;
}