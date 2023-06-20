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

	int N = 0, K = 0;
	int result = 0;

	cin >> N >> K;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if ((K / v[i]) > 0)
		{
			result += K / v[i];
			K %= v[i];
		}
	}

	cout << result << "\n";

	return 0;
}