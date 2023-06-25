#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int arr[2001];
static bool pdm[2001][2001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		pdm[i][i] = true;

		if (i < N)
		{
			if (arr[i] == arr[i + 1])
			{
				pdm[i][i + 1] = true;
			}
		}
	}

	for (int i = 3; i <= N; i++)
	{
		for (int j = i - 2; j >= 1; j--)
		{
			if (arr[i] == arr[j] && pdm[j + 1][i - 1])
			{
				pdm[j][i] = true;
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e;

		cin >> s >> e;

		cout << pdm[s][e] << "\n";
	}

	return 0;
}