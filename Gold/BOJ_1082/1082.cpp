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

	int N, M;

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	cin >> M;

	vector<int> result;

	int a = 51, b = 51;
	int ai = 0, bi = 0;

	for (int i = 0; i < N; i++)
	{
		if (v[i] < b)
		{
			b = v[i];
			bi = i;
		}

		if (i > 0 && v[i] < a)
		{
			a = v[i];
			ai = i;
		}
	}

	result.push_back(ai);
	M -= v[ai];

	if (M < 0)
	{
		cout << "0";
		return 0;
	}

	if (N > 1)
	{
		while (M >= v[bi])
		{
			result.push_back(bi);
			M -= v[bi];
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (result[i] < j)
			{
				if (M >= v[j] - v[result[i]])
				{
					M -= (v[j] - v[result[i]]);
					result[i] = j;
					break;
				}
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}

	return 0;
}