#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int N, M;
static int arr[9] = { 0 };
static bool visited[9] = { false };

void DFS(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			DFS(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(0);

	return 0;
}