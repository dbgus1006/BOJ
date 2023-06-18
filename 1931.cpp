#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		cin >> v[i].second;
	}

	sort(v.begin(), v.end(), comp);

	int cnt = 1;
	int time = v[0].second - v[0].first;
	pair<int, int> now = v[0];

	for (int i = 1; i < N; i++)
	{
		if (now.second > v[i].first)
		{
			if (now.second - now.first > v[i].second - v[i].first && now.second >= v[i].second)
			{
				now = v[i];
			}
			continue;
		}
		
		++cnt;
		now = v[i];
	}

	cout << cnt << "\n";

	return 0;
}

// 3
// 1 5
// 4 6
// 5 7
// 반례 찾음. 종료 시간을 넘기는 경우는 짧아도 교체할 필요가 없다.