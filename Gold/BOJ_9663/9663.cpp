#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int col[15];
static int N, ans = 0;

bool check(int level)
{
	for (int i = 0; i < level; i++)
	{
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
		{
			return false;
		}
	}
	
	return true;
}

void Back_tracking(int queen)
{
	
	if (queen == N)
	{
		ans++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			col[queen] = i;
			
			if (check(queen))
			{
				Back_tracking(queen + 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Back_tracking(0);

	cout << ans << "\n";

	return 0;
}