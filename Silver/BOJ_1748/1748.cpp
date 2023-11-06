#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#define ll long long
using namespace std;

static ll N, res = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string str = to_string(N);
	ll len = str.length();

	if (len < 2)
	{
		cout << N << "\n";
		return 0;
	}

	for (int i = 1; i < len; i++)
	{
		res += i * (9 * pow(10, i - 1));
	}

	ll num = pow(10, len - 1);
	num = (N % num + 1) * len + (N / num - 1) * num * len;

	res += num;

	cout << res << "\n";

	return 0;
}