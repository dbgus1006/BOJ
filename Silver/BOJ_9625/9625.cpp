#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int pibo[45];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;

	cin >> K;

	pibo[0] = 1;
	pibo[1] = 1;

	for (int i = 2; i < 45; i++)
	{
		pibo[i] = pibo[i - 1] + pibo[i - 2];
	}

	if (K == 1)
	{
		cout << "0 1\n";
	}
	else
	{
		cout << pibo[K - 2] << " " << pibo[K - 1] << "\n";
	}

	return 0;
}