#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

static int N, r, c, res;

void Divide_Z(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << res << "\n";
		return;
	}

	if (r >= y && r < y + size && c >= x && c < x + size)
	{
		Divide_Z(y, x, size / 2);
		Divide_Z(y, x + (size / 2), size / 2);
		Divide_Z(y + (size / 2), x, size / 2);
		Divide_Z(y + (size / 2), x + (size / 2), size / 2);
	}
	else
	{
		res += (size * size);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	Divide_Z(0, 0, pow(2, N));

	return 0;
}