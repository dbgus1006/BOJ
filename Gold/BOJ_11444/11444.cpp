#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define ll long long
#define key 1000000007
using namespace std;

static ll N;
static map<ll, ll> m;

ll fibo(ll n)
{
	if (m[n])
	{
		return m[n];
	}
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	ll Fn = fibo(n / 2) % key;

	if (n % 2 == 0)
	{
		ll Fn_m1 = fibo(n / 2 - 1) % key;

		return m[n] = (Fn * Fn + Fn * (2 * Fn_m1)) % key;
	}

	ll Fn_p1 = fibo(n / 2 + 1) % key;

	return m[n] = (Fn * Fn + Fn_p1 * Fn_p1) % key;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cout << fibo(N) << "\n";

	return 0;
}