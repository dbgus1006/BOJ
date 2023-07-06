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

	int A, B;

	cin >> A >> B;

	int cnt = 0;

	while (A < B)
	{
		if (B % 10 == 1)
		{
			B = B / 10;
		}
		else if (B % 2 == 0)
		{
			B = B / 2;
		}
		else
		{
			cout << "-1\n";
			return 0;
		}
		cnt++;
	}

	if (A == B)
	{
		cout << cnt + 1 << "\n";
	}
	else
	{
		cout << "-1\n";
	}

	return 0;
}