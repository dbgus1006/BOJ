#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

static vector<ll> v_list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		ll num;
		
		cin >> num;

		if (num == 0)
		{
			v_list.pop_back();
			continue;
		}

		v_list.push_back(num);
	}

	ll res = 0;

	for (int i = 0; i < v_list.size(); i++)
	{
		res += v_list[i];
	}

	cout << res << "\n";

	return 0;
}