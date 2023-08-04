#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int res5 = N / 5, res3;

	while (true)
	{
		if (res5 < 0)
		{
			cout << "-1\n";
			return 0;
		}
		else if ((N - (5 * res5)) % 3 == 0)
		{
			res3 = (N - (5 * res5)) / 3;
			cout << res3 + res5 << "\n";
			return 0;
		}
		res5--;
	}

	return 0;
}