#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

static bool arr[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		double x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int n;

		cin >> n;

		fill(arr, arr + n, false);

		for (int j = 0; j < n; j++)
		{
			double cx, cy, r;

			cin >> cx >> cy >> r;

			bool st = false, ed = false;

			if (sqrt(pow(cx - x1, (double)2) + pow(cy - y1, (double)2)) < r)
			{
				st = true;
			}
			if (sqrt(pow(cx - x2, (double)2) + pow(cy - y2, (double)2)) < r)
			{
				ed = true;
			}

			if (st == true && ed == true)
			{
				arr[j] = false;
			}
			else if (st == false && ed == false)
			{
				arr[j] = false;
			}
			else
			{
				arr[j] = true;
			}
		}

		int cnt = 0;

		for (int j = 0; j < n; j++)
		{
			if (arr[j])
			{
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}