#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> node;
static bool visited[50][50] = { false, };
static bool isTarget[50][50] = { false, };
static queue<node> q;
static queue<node> check;
static int T, N, M, K, ans = 0;
static int mx[4] = {-1, 1, 0, 0};
static int my[4] = {0, 0, 1, -1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;

		for (int k = 0; k < K; k++)
		{
			int x, y;

			cin >> x >> y;

			isTarget[y][x] = true;
			q.push(node(y, x));
		}

		while (!q.empty())
		{
			node now = q.front();
			int x = now.second;
			int y = now.first;
			q.pop();

			if (!visited[y][x])
			{
				ans++;
				check.push(node(y, x));

				while (!check.empty())
				{
					int check_y = check.front().first;
					int check_x = check.front().second;
					check.pop();

					if (!visited[check_y][check_x])
					{
						visited[check_y][check_x] = true;

						for (int i = 0; i < 4; i++)
						{
							if (check_y + my[i] >= 0 && check_y + my[i] <= 49 && check_x + mx[i] >= 0 && check_x + mx[i] <= 49)
							{
								if (isTarget[check_y + my[i]][check_x + mx[i]])
								{
									check.push(node(check_y + my[i], check_x + mx[i]));
								}
							}
						}
					}
				}
			}
		}

		fill(&visited[0][0], &visited[49][50], false);
		fill(&isTarget[0][0], &isTarget[49][50], false);
		cout << ans << "\n";
		ans = 0;
	}
	
	

	return 0;
}