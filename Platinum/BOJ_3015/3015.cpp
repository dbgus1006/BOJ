#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define ll long long
using namespace std;

typedef pair<int, int> node;
static stack<node> s;
static int N, now;
static ll res = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> now;

		while (!s.empty() && s.top().first < now)
		{
			res += s.top().second;
			s.pop();
		}

		if (s.empty())
		{
			s.push(node(now, 1));
		}
		else
		{
			if (s.top().first == now)
			{
				int person = s.top().second;
				s.pop();

				if (!s.empty())
				{
					res++;
				}

				res += person;
				s.push(node(now, person + 1));
			}
			else
			{
				res++;
				s.push(node(now, 1));
			}
		}
	}

	cout << res << "\n";

	return 0;
}