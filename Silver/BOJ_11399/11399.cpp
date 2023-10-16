#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

static vector<ll> v;
static int N;
static ll res = 0, tmp = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		tmp += v[i];
		res += tmp;
	}

	cout << res << "\n";

	return 0;
}