#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int result = 0;

	cin >> N;

	int arr[2001] = {0};

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int b = 0, e = N - 1;

	for (int i = 0; i < N; i++)
	{
		b = 0, e = N - 1;
		while (b != e)
		{
			if (b == i)
			{
				++b;
				continue;
			}
			else if (e == i)
			{
				--e;
				continue;
			}

			if (arr[b] + arr[e] > arr[i])
			{
				--e;
			}
			else if (arr[b] + arr[e] < arr[i])
			{
				++b;
			}
			else if (arr[b] + arr[e] == arr[i])
			{
				++result;
				break;
			}
		}
	}


	cout << result << "\n";

	return 0;
}