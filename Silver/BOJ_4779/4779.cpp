#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

static int N;

void Cantorian(int len);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> N)
	{
		Cantorian(pow(3, N));
		cout << "\n";
	}

	return 0;
}

void Cantorian(int len)
{
	if (len == 1)
	{
		cout << "-";
		return;
	}

	Cantorian(len / 3);
	for (int i = 0; i < len / 3; i++)
	{
		cout << " ";
	}
	Cantorian(len / 3);
}