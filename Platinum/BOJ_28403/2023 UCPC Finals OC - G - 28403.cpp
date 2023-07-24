#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

static string card;
static int H_arr[1000001];
static int S_arr[1000001];
static int cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	cin.ignore();

	getline(cin, card);

	for (int i = 1; i <= N; i++)
	{
		if (card[i - 1] == 'S')
		{
			S_arr[i] = S_arr[i - 1] + 1;
			H_arr[i] = H_arr[i - 1];
		}
		else if (card[i - 1] == 'H')
		{
			H_arr[i] = H_arr[i - 1] + 1;
			S_arr[i] = S_arr[i - 1];
		}
	}

	for (int K = 1; K <= N; K++)
	{
		cnt = 0;

		for (int i = K; i <= N;)
		{
			cnt++;

			if (S_arr[i] < K)
			{
				i = i + (K - S_arr[i]);

				if (i > N)
				{
					cout << cnt << " ";
					break;
				}

				continue;
			}
			else
			{
				cout << cnt << " ";
				break;
			}
		}
	}

	return 0;
}