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

	int N = 0;
	long result = 0;

	cin >> N;

	priority_queue<long, vector<long>, greater<long>> pq;
	long num = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	if (N == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

	long comp = pq.top();
	pq.pop();
	long a, b;

	while (!pq.empty())
	{
		a = pq.top();
		pq.pop();
		if (!pq.empty())
		{
			if (comp + a > a + pq.top())
			{
				b = pq.top();
				pq.pop();
				result += (a + b);
				pq.push(a + b);
			}
			else
			{
				comp += a;
				result += comp;
			}
		}
		else
		{
			comp += a;
			result += comp;
		}

	}

	cout << result << "\n";

	return 0;
}