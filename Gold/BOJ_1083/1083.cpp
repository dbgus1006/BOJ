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

	int N, S;
	bool chk = true;

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	cin >> S;

	for (int j = 0; j < N; j++)
	{
		int max = 0;
		int max_idx = 0;
		int cnt = 0;

		for (int i = j; i < N; i++)
		{
			cnt++;
			if (v[i] > max)
			{
				max = v[i];
				max_idx = i;
			}
			if (cnt > S)
			{
				break;
			}
		}

		for (int i = max_idx; i > j; i--)
		{
			swap(v[i], v[i - 1]);
			S--;
		}

		if (S < 1)
		{
			break;
		}
	}

	for (int k = 0; k < N; k++)
	{
		cout << v[k] << " ";
	}

	return 0;
}