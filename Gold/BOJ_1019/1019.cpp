#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int res[10];

void subcnt(int num, int ten)
{
	while (num > 0)
	{
		res[num % 10] += ten;
		num /= 10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start = 1, end, ten = 1;

	cin >> end;

	while (start <= end)
	{
		while (start % 10 != 0 && start <= end)
		{
			subcnt(start, ten);
			start++;
		}

		if (start > end)
		{
			break;
		}

		while (end % 10 != 9 && start <= end)
		{
			subcnt(end, ten);
			end--;
		}

		int cnt = (end / 10 - start / 10 + 1) * ten;

		for (int i = 0; i < 10; i++)
		{
			res[i] += cnt;
		}

		start /= 10;
		end /= 10;
		ten *= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}