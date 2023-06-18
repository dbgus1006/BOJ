#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long A, B;
	int cnt = 0;

	cin >> A >> B;

	long arr[10000001];
	fill_n(arr, 10000001, 1);

	arr[0] = 0;
	arr[1] = 0;

	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (arr[i] == 1)
		{
			int k = i + i;

			while (k <= 10000000)
			{
				arr[k] = 0;
				k += i;
			}
		}
	}

	for (int i = 2; i <= 10000001; i++)
	{
		if (arr[i] == 1)
		{
			double pn = i;
			while ((double)i <= (double)B / (double)pn)
			{
				if ((double)i >= (double)A / (double)pn)
					cnt++;
				pn = pn * i;
			}
		}
	}
	
	cout << cnt << "\n";
		
	return 0;
}