#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 9
using namespace std;

static int N, M;
static int arr[MAX] = { 0 };
static int seq[MAX] = { 0 };
static bool visited[MAX] = { false };

void DFS(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	int chk = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && arr[i] != chk)
		{
			visited[i] = true;
			chk = arr[i];
			seq[cnt] = arr[i];
			DFS(i, cnt + 1);
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

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sort(arr + 1, arr + N + 1);

	DFS(1, 0);

	return 0;
}