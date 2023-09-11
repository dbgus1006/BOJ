#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

static deque<int> dq;
static vector<int> v_list;
static int N, M, res = 0, L, R;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int num;

		cin >> num;

		v_list.push_back(num);
	}

	for (int i = 0; i < M; i++)
	{
		int chk = v_list[i];

		for (int j = 0; j < dq.size(); j++)
		{
			if (dq[j] == chk)
			{
				L = j;
				R = dq.size() - j;
				break;
			}
		}

		if (L >= R)
		{
			while (true)
			{
				if (dq.front() == chk)
				{
					dq.pop_front();
					break;
				}

				dq.push_front(dq.back());
				dq.pop_back();
				res++;
			}
		}
		else if (L < R)
		{
			while (true)
			{
				if (dq.front() == chk)
				{
					dq.pop_front();
					break;
				}

				dq.push_back(dq.front());
				dq.pop_front();
				res++;
			}
		}
	}

	cout << res << "\n";

	return 0;
}