#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N, res = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 100; i <= N; i++)
	{
		if ((i / 100) - (i % 100 / 10) == (i % 100 / 10) - (i % 10))
		{
			res++;
		}
	}

	if (N < 10)
	{
		res += N;
	}
	else if (N < 100)
	{
		res += (N - 10 + 1) + 9;
	}
	else
	{
		res += 99;
	}

	cout << res << "\n";

	return 0;
}