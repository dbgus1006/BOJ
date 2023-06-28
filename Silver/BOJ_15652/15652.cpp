#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 9
using namespace std;

static int N, M;
static int arr[MAX] = { 0 };

void DFS(int num, int cnt)
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

	for (int i = num; i <= N; i++)
	{
		arr[cnt] = i;
		DFS(i, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(1, 0);

	return 0;
}