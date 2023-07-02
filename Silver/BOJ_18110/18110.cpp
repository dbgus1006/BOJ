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

	int N = 0;

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	float fn = (round((float)N * 0.15));

	int result = 0;

	for (int i = (int)fn; i < N - (int)fn; i++)
	{
		result += v[i];
	}

	cout << (int)round((float)result / (N - (2 * fn))) << "\n";

	return 0;
}