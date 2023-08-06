#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;

	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		queue<node> q;
		int arr[10] = { 0, };

		for (int i = 0; i < N; i++)
		{
			int num;

			cin >> num;

			for (int j = 1; j < num; j++)
			{
				arr[j]++;
			}
			q.push(node(num, i));
		}

		int cnt = 1;

		while (!q.empty())
		{
			node now = q.front();
			q.pop();

			if (arr[now.first])
			{
				q.push(now);
			}
			else
			{
				if (now.second == M)
				{
					cout << cnt << "\n";
					break;
				}

				for (int j = 1; j < now.first; j++)
				{
					arr[j]--;
				}

				cnt++;
			}
		}
	}

	return 0;
}