#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

static vector<deque<int>> v;
static int S;
static int cnt = 0;

void DFS(int node)
{
	if (node == S)
	{
		return;
	}

	if (v[node].empty())
	{
		cnt++;
		return;
	}

	for (int i : v[node])
	{
		DFS(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	v.resize(N);

	int root = 0;

	for (int i = 0; i < N; i++)
	{
		int node;

		cin >> node;

		if (node == -1)
		{
			root = i;
			continue;
		}

		v[node].push_back(i);
	}

	cin >> S;

	for (int i = 0; i < N; i++)
	{
		if (!v[i].empty())
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == S)
				{
					v[i].erase(v[i].begin() + j);
				}
			}
		}
	}

	DFS(root);

	cout << cnt << "\n";

	return 0;
}