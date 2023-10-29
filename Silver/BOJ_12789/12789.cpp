#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

static int N;
static stack<int> stk;
static queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	int now = 1;

	while (true)
	{
		if (q.empty() && stk.empty())
		{
			cout << "Nice\n";
			break;
		}

		if (!q.empty())
		{
			if (q.front() != now)
			{
				if (!stk.empty() && stk.top() == now)
				{
					stk.pop();
					now++;
				}
				else
				{
					stk.push(q.front());
					q.pop();
				}
			}
			else
			{
				q.pop();
				now++;
			}
		}
		else
		{
			if (stk.top() != now)
			{
				cout << "Sad\n";
				break;
			}
			else
			{
				stk.pop();
				now++;
			}
		}
	}

	return 0;
}