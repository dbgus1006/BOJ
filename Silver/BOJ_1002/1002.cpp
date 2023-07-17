#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	double x1, y1, r1, x2, y2, r2;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double tmp = sqrt(pow(x2 - x1,(double) 2) + pow(y2 - y1,(double) 2));

		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
			{
				cout << "-1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (r1 >= r2)
		{
			if (r2 + tmp < r1 || tmp - r2 > r1)
			{
				cout << "0\n";
			}
			else if (r2 + tmp == r1 || tmp - r2 == r1)
			{
				cout << "1\n";
			}
			else
			{
				cout << "2\n";
			}
		}
		else if (r2 > r1)
		{
			if (r1 + tmp < r2 || tmp - r1 > r2)
			{
				cout << "0\n";
			}
			else if (r1 + tmp == r2 || tmp - r1 == r2)
			{
				cout << "1\n";
			}
			else
			{
				cout << "2\n";
			}
		}
	}

	return 0;
}