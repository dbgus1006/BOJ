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
	int result = 0;

	cin >> N >> M;

	vector<int> v;
	int num;

	v.push_back(0);

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		v.push_back(v[i - 1] + num);
	}

	int b, e;

	for (int i = 0; i < M; i++)
	{
		cin >> b >> e;

		result = v[e] - v[b - 1];

		cout << result << "\n";
	}

	return 0;
}