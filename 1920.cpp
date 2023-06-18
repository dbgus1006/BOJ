#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int arr[100000];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int tg, st = 0, ed = N;
		cin >> tg;

		int pv = ed / 2;

		while (true)
		{
			if (arr[pv] == tg)
			{
				cout << "1\n";
				break;
			}
			else if (pv == st || pv == ed)
			{
				cout << "0\n";
				break;
			}
			else if (arr[pv] > tg) // l
			{
				ed = pv;
				pv = (st + pv) / 2;
			}
			else if (arr[pv] < tg) // r
			{
				st = pv;
				pv = (ed + pv) / 2;
			}	
		}
	}

	return 0;
}