#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	long long result = 0;

	long long mod[1001] = { 0 };

	cin >> N >> M;

	vector<long long> v;
	int num;

	cin >> num;
	v.push_back(num);
	++mod[v[0] % M];

	for (int i = 1; i < N; i++)
	{
		cin >> num;
		v.push_back(v[i - 1] + num);
		++mod[v[i] % M];
	}

	for (int j = 0; j < 1000; j++)
	{
		if (mod[j] > 1)
			result += mod[j] * (mod[j] - 1) / 2;
	}

	result += mod[0];

	cout << result;

	return 0;
}