#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, int> node;
static int N, res = 0;
static priority_queue<int, vector<int>, greater<int>> res_cnt;
static int map[25][25] = { 0, };
static bool visited[25][25] = { false, };
static int xx[4] = { 0, 0, 1, -1 };
static int yy[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		string str;

		getline(cin, str);

		for (int j = 0; j < N; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == false)
			{
				queue<node> q;
				q.push(node(i, j));
				res++;
				int cnt = 0;

				while (!q.empty())
				{
					int now_x = q.front().second;
					int now_y = q.front().first;
					q.pop();

					if (visited[now_y][now_x])
					{
						continue;
					}

					visited[now_y][now_x] = true;
					cnt++;

					for (int p = 0; p < 4; p++)
					{
						if (now_y + yy[p] >= 0 && now_y + yy[p] < N && now_x + xx[p] >= 0 && now_x + xx[p] < N)
						{
							if (map[now_y + yy[p]][now_x + xx[p]] == 1 && visited[now_y + yy[p]][now_x + xx[p]] == false)
							{
								q.push(node(now_y + yy[p], now_x + xx[p]));
							}
						}
					}
				}

				res_cnt.push(cnt);
			}
		}
	}

	cout << res << "\n";

	while (!res_cnt.empty())
	{
		cout << res_cnt.top() << "\n";
		res_cnt.pop();
	}

	return 0;
}