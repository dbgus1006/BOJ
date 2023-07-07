#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;

	cin >> T;

	int arr[41] = { 0, 1 };

	for (int i = 2; i < 41; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			cout << "1 0\n";
		}
		else
		{
			cout << arr[num - 1] << " " << arr[num] << "\n";
		}
	}

	return 0;
}