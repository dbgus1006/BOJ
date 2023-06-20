#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N = 0;

	cin >> N;

	long long result = N;

	for (long long i = 2; i <= sqrt(N); i++)
	{
		if (N % i != 0)
			continue;

		result = result - (result / i);

		while (N % i == 0)
		{
			N /= i;
		}
	}

	if (N > 1)
	{
		result = result - (result / N);
	}

	cout << result << "\n";

	return 0;
}