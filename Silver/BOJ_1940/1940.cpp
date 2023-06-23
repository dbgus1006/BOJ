#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int st = 0;
	int ed = N - 1;
	int cnt = 0;

	while (st < ed)
	{
		if (v[st] + v[ed] < M)
		{
			++st;
		}
		else if (v[st] + v[ed] > M)
		{
			--ed;
		}
		else
		{
			++st;
			--ed;
			++cnt;
		}
	}

	cout << cnt << "\n";

	return 0;
}