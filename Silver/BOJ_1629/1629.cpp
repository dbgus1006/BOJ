#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

static ll A, B, C, ans;

ll power(ll n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return A % C;
	}

	ans = power(n / 2) % C;

	if (n % 2 == 0)
	{
		return ans * ans % C;
	}
	return ans * ans % C * A % C;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	cout << power(B) << "\n";

	return 0;
}