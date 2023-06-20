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

	long long min, max;

	cin >> min >> max;

	vector<bool> chk(max - min + 1);

	for (long long i = 2; i * i <= max; i++)
	{
		long long sqn = i * i;
		long long s = min / sqn;

		if (min % sqn != 0)
		{
			s++;
		}

		for (long long j = s; j * sqn <= max; j++)
		{
			chk[(int)((j * sqn) - min)] = true;
		}
	}

	int cnt = 0;

	for (int i = 0; i <= max - min; i++)
	{
		if (!chk[i])
		{
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}