#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

static vector<ll> v_time;
static int N, ans = 1;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		ll a, b;

		cin >> a >> b;

		v_time.push_back(a - b);
	}

	sort(v_time.begin(), v_time.end());

	if (v_time.size() % 2 == 0)
	{
		ans = v_time[v_time.size() / 2] - v_time[v_time.size() / 2 - 1] + 1;
	}

	cout << ans << "\n";

	return 0;
}