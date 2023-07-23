#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int result = 0;

	cin >> N;

	vector<pair<int, int>> v;
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(make_pair(num, i));
	}

	stable_sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		if (result < v[i].second - i)
			result = v[i].second - i;
	}

	cout << result + 1 << "\n";

	return 0;
}