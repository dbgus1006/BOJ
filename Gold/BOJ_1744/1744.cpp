#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int result = 0;

	cin >> N;

	deque<int> dq;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		dq.push_back(n);
	}

	if (dq.size() == 1)
	{
		cout << dq.front() << "\n";
		return 0;
	}

	sort(dq.begin(), dq.end());

	if (dq.front() == 0 && dq.back() == 0)
	{
		cout << "0\n";
		return 0;
	}

	while (!(dq.empty()) && dq.front() < 0)
	{
		int a, b;
		a = dq.front();
		dq.pop_front();
		
		if (!(dq.empty()) && dq.front() < 1)
		{
			b = dq.front();
			dq.pop_front();

			result += (a * b);
		}
		else
		{
			result += a;
		}
	}

	while (!(dq.empty()) && dq.back() > 0)
	{
		int a, b;
		a = dq.back();
		dq.pop_back();

		if (!(dq.empty()) && dq.back() > 1)
		{
			b = dq.back();
			dq.pop_back();

			result += (a * b);
		}
		else
		{
			result += a;
		}
	}

	cout << result << "\n";

	return 0;
}