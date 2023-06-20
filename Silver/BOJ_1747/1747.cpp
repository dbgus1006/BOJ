#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	int arr[2000001];
	fill_n(arr, 2000001, 1);

	arr[0] = 0;
	arr[1] = 0;

	for (int i = 2; i <= sqrt(2000001); i++)
	{
		if (arr[i] == 1)
		{
			int temp = i + i;
			while (temp < 2000001)
			{
				arr[temp] = 0;
				temp += i;
			}
		}
	}


	for (int i = N; ; i++)
	{
		if (arr[i] == 1)
		{
			string str = to_string(i);
			char const* pdm = str.c_str();

			int s = 0, e = str.size() - 1;

			while (s < e)
			{
				if (pdm[s] != pdm[e])
				{
					break;
				}
				++s;
				--e;
			}

			if (s >= e)
			{
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}