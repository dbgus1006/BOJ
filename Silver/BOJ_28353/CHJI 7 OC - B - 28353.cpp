#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int st = 0, ed = N - 1;
	int cnt = 0;

	while (st < ed)
	{
		if (v[st] + v[ed] <= K)
		{
			cnt++;
			st++;
			ed--;
		}
		else if (K - v[st] < v[ed])
		{
			ed--;
		}
	}

	cout << cnt << "\n";

	return 0;
}