#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

static vector<pair<int, int>> v;
static set<double> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int  x, y;
			cin >> x >> y;

			v.push_back(make_pair(x, y));
		}

		for (int j = 0; j < 4; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				double edge = sqrt(pow(v[j].first - v[k].first, (double)2) + pow(v[j].second - v[k].second, (double)2));

				s.insert(edge);
			}
		}

		if (s.size() == 2)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}

		v.clear();
		s.clear();
	}

	return 0;
}