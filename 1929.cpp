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

	int N = 0, M = 0;

	cin >> N >> M;

	vector<int> v(M + 1, 1);

	v[1] = 0;

	for (int i = 2; i < M + 1; i++)
	{
		if (v[i] == 1)
		{
			for (int j = i * 2; j < M + 1; j += i)
			{
				v[j] = 0;
			}
		}
	}

	for (int i = N; i < M + 1; i++)
	{
		if (v[i] == 1)
			cout << i << "\n";
	}

	return 0;
}