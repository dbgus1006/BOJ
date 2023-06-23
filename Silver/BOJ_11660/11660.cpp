/*#include <iostream>
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

	cin >> N >> M;

	vector<vector<int>> original_arr(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> sum_arr(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> original_arr[i][j];

			sum_arr[i][j] = sum_arr[i][j - 1] + sum_arr[i - 1][j] - sum_arr[i - 1][j - 1] + original_arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int sx, sy, ex, ey;

		cin >> sx >> sy >> ex >> ey;

		cout << sum_arr[ex][ey] - sum_arr[ex][sy - 1] - sum_arr[sx - 1][ey] + sum_arr[sx - 1][sy - 1] << "\n";
	}

	return 0;
}*/