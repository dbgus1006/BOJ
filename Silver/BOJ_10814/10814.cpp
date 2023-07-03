#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;
	cin.ignore();

	vector<pair<int, string>> v;

	for (int i = 0; i < N; i++)
	{
		int num;
		string str;

		cin >> num >> str;

		v.push_back(make_pair(num, str));
	}

	stable_sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}